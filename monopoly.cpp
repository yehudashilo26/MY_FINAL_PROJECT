#include "monopoly.h"
#include "tile.h"
#include "tilefactory.h"
#include <cstdlib>
#include <ctime>
#include <qdebug.h>
#include <qlogging.h>
#include <stdexcept>
#include <iostream>

#define MAX_PLAYERS 8
Monopoly *Monopoly::instance = nullptr;


void Monopoly::addObserver(GameObserver *observer)
{
    observers.push_back(observer);
}

void Monopoly::notify(const Event &event)
{
    for (auto observer : observers)
    {
        observer->onNotify(event);
    }
}

void Monopoly::nextPlayer()
{
    // get the next player if its not bankrupt
    do
    {
        currentPlayer = &players[(currentPlayer->getID()) % players.size()];
    } while (currentPlayer->isBankrupt);
}

Monopoly::Monopoly()
{
    std::srand(std::time(0)); // Seed the random number generator
    players.reserve(MAX_PLAYERS);
}

Monopoly::~Monopoly() {}

Monopoly *Monopoly::getInstance()
{
    if (!instance)
    {
        instance = new Monopoly();
    }
    return instance;
}

void Monopoly::setBoard(const json &j)
{
    if (isGameStarted)
    {
        throw std::runtime_error("Game already started");
    }

    // Check if the JSON object contains the "tiles" key and that it's an array
    if (!j.contains("tiles") || !j["tiles"].is_array())
    {
        throw std::runtime_error("Invalid JSON format, expected 'tiles' to be an array.");
    }

    const auto &tiles = j["tiles"]; // Get the array of tiles from the JSON object

    // Check if the size of the "tiles" array matches the expected BOARD_SIZE
    if (tiles.size() != BOARD_SIZE)
    {
        throw std::runtime_error("Invalid board size, expected " + std::to_string(BOARD_SIZE) + " tiles.");
    }

    // Clear and resize the board to hold exactly BOARD_SIZE tiles
    board.clear();
    board.resize(BOARD_SIZE);

    // Iterate over the tiles array and create Tile objects
    for (const auto &tile_data : tiles)
    {
        try
        {
            // Assuming TileFactory::createTile takes JSON data and returns a std::unique_ptr<Tile>
            std::unique_ptr<Tile> newTile = TileFactory::createTile(this, tile_data);

            if (!newTile)
            {
                throw std::runtime_error("Tile creation failed.");
            }

            int id = newTile->getId();
            if (newTile->getType() == "Jail")
            {
                jailIndex = id;
            }

            if (newTile->getType() == "Go")
            {
                goIndex = id;
            }

            if (id < 1 || id > BOARD_SIZE)
            {
                throw std::runtime_error("Invalid tile ID: " + std::to_string(id));
            }

            // Place the new tile in the correct position in the board (adjust ID to be zero-based)
            board[id - 1] = std::move(newTile);
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error creating tile: " + std::string(e.what()));
        }
    }
}

std::vector<const Tile *> Monopoly::getBoard() const
{
    std::vector<const Tile *> tilePtrs;
    for (const auto &tile : board)
    {
        tilePtrs.push_back(tile.get()); // Return raw pointers to tiles
    }
    return tilePtrs;
}

// Return a vector of const pointers to players (non-modifiable)
std::vector<const Player *> Monopoly::getPlayers() const
{
    std::vector<const Player *> playerPtrs;
    for (const auto &player : players)
    {
        playerPtrs.push_back(&player);
    }
    return playerPtrs;
}

const Player &Monopoly::getCurrentPlayer()
{
    return *currentPlayer;
}

Player *const& Monopoly::getCurrentPlayerPtr(){
    return currentPlayer;
};

const Player &Monopoly::addPlayer(const std::string &name)
{
    if (isGameStarted)
    {
        throw std::runtime_error("Game already started");
    }

    if (players.size() >= MAX_PLAYERS)
    {
        throw std::runtime_error("Maximum number of players reached");
    }

    if (name.empty())
    {
        throw std::runtime_error("Player name cannot be empty");
    }

    for (const auto &player : players)
    {
        if (player.getName() == name)
        {
            throw std::runtime_error("Player name already exists");
        }
    }

    players.emplace_back(name, players.size()+1, START_BALANCE);// to make sure the object is the same
    return players.back();
}
// void Monopoly::startGame()

Tile *Monopoly::getModifiableTile(const Tile *tile)
{
    try
    {
        int id = tile->getId()-1;                    // comparing by tile id
        Tile *modifiableTile = board.at(id).get(); // get the tile pointer from the unique_ptr

        // Check if the modifiable tile pointer is the same as the const tile pointer
        if (modifiableTile == tile)
        {
            return modifiableTile; // Return the modifiable tile if they are the same object
        }
        else
        {
            throw std::runtime_error("Tile mismatch: Tile not found");
        }
    }
    catch (const std::out_of_range &e)
    {
        throw std::runtime_error("Tile not found: Index out of range");
    }
}

const Tile *Monopoly::getPlayerTile(const Player &player) const
{
    size_t playerId = player.getID()-1;
    try{
        if (&players[playerId] == &player)
        {
            return board[players[playerId].getPosition()].get();
        }
        else
        {
            throw std::runtime_error("Player not found");
        }
        }
    catch (const std::out_of_range &e)
    {
        throw std::runtime_error("Player not found: Index out of range");
    }
}

const Player &Monopoly::getPlayerByName(const std::string &name)
{
    for (const auto &player : players)
    {
        if (player.getName() == name)
        {
            return player;
        }
    }
    throw std::runtime_error("Player not found");
}

void Monopoly::startGame()
{
    if (isGameStarted)
    {
        throw std::runtime_error("Game already started");
    }

    if (players.size() < 2)
    {
        throw std::runtime_error("Not enough players to start the game");
    }

    currentPlayer = &players[0]; // Set the first player as the current player
    isGameStarted = true;
}

void Monopoly::RollDice(const Player &player)
{
    checkPlayerTurn(player);
    checkPlayerCanRoll(player);
    int dice1 = std::rand() % 6 + 1; // Roll the dice (1-6)
    int dice2 = std::rand() % 6 + 1; // Roll the dice (1-6)

    int total = dice1 + dice2;
    std::cout<<"Rolled " << dice1 << "," << dice2 << std::endl;

    hasPlayerRolled = true;
    if (dice1 == dice2)
    {            
        notify(PlayerRolledDoublesEvent(player));
        doublesCount++;
        if (currentPlayer->isInJail())
        {
            currentPlayer->setInJail(false);
            currentPlayer->setTurnsInJail(0);
            doublesCount = 0;
            notify(PlayerIsOutOfJailEvent(player));
        }

        else if (doublesCount == MAX_DOUBLES)
        {
            moveToJail(*currentPlayer);
            doublesCount = 0;
            notify(PlayerIsInJailEvent(player));
        }
        else
        {
            hasPlayerRolledDoubles = true;
            doublesCount++;
        }
    }
    else{
        notify(PlayerRolledDiceEvent(*currentPlayer,dice1,dice2));
    hasPlayerRolledDoubles=false;
    doublesCount = 0;
    }
    movePlayer(*currentPlayer,total);


    // Move the player


}

void Monopoly::moveToJail(Player &player)
{
    player.setPosition(jailIndex);
    player.setInJail(true);
    player.setTurnsInJail(0);
    hasPlayerRolled = false;
    hasPlayerRolledDoubles = false;
    doublesCount = 0;
    nextPlayer();
    notifyObservers(PlayerIsInJailEvent(player));
}


void Monopoly::checkPlayerTurn(const Player &player)
{
    if (!isGameStarted)
    {
        throw std::runtime_error("Game not started");
    }

    if (&player != currentPlayer)
    {
        throw std::runtime_error("Not the current player's turn");
    }

    if (player.isBankrupt)
    {
        throw std::runtime_error("Player is bankrupt");
    }

    if (player.isInJail() && player.getTurnsInJail() >= 3)
    {
        throw std::runtime_error("Player has been in jail for 3 turns must pay bail or use chance card");
    }
    
}

void Monopoly::checkPlayerCanRoll(const Player &player)
{
    if (hasPlayerRolled && !hasPlayerRolledDoubles)
    {
        throw std::runtime_error("Player has already rolled the dice");
    }

}

void Monopoly::checkPlayerRolled(const Player &player)
{
    if (!hasPlayerRolled)
    {
        throw std::runtime_error("Player has not rolled the dice");
    }
}

void Monopoly::notifyObservers(const Event &event)
{
    for (auto observer : observers)
    {
        observer->onNotify(event);
    }
}

void Monopoly::endTurn(const Player &player)
{
    checkPlayerTurn(player);
    if (hasPlayerRolledDoubles)
    {
        throw std::runtime_error("Player has rolled doubles, must roll again");
    }

    if (!hasPlayerRolled)
    {
        throw std::runtime_error("Player has not rolled the dice");
    }

    hasPlayerRolled = false;

    nextPlayer();
    notify(PlayerTurnEndEvent(player));
}

void Monopoly::buyProperty(const Player &player, const Tile &tile)
{
    checkPlayerTurn(player); // after this we can use the current Player Pointer.
    checkPlayerRolled(player);

    // check if tile is buyable class
    if (Buyable *buyable = dynamic_cast<Buyable *>(getModifiableTile(&tile)))
    {
        if (buyable->getOwner() != nullptr)
        {
            throw std::runtime_error("Tile is already owned");
        }

        if (currentPlayer->getBalance() < buyable->getPrice())
        {
            throw std::runtime_error("Insufficient funds to buy property");
        }

        currentPlayer->subtractFromBalance(buyable->getPrice());
        buyable->setOwner(currentPlayer);
        notify(PlayerBoughtPropertyEvent(player, tile));
    }

    else
    {
        throw std::runtime_error("Tile is not buyable");
    }

};

void Monopoly::buyHouse(const Player &player, const Tile &tile)
{};

void Monopoly::buyHotel(const Player &player, const Tile &tile)
{};

void Monopoly::payBail(const Player &player)
{};

void Monopoly::movePlayer(Player &player, int spaces)
{
    int position = player.getPosition();
    int newPosition = (position + spaces) % BOARD_SIZE;
    if (newPosition < position)
    {
        player.addToBalance(200);
    }

    player.setPosition(newPosition);
    board[newPosition]->landOn(*this,&player);
    // notify(PlayerMovedEvent(player, spaces));
    return;
    // notify(PlayerMovedEvent(player, spaces));
}
