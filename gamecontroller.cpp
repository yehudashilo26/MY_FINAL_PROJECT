#include "gamecontroller.h"
#include <fstream>

GameController::GameController():GameObserver()
{
    game = Monopoly::getInstance();
    gui = new GameView(this);
}

const Player &GameController::addPlayer(const std::string &name)
{
    return game->addPlayer(name);
}

void GameController::loadBoard(const std::string &json_path)
{
 // check if the file exists
    std::ifstream file(json_path);
    if (!file)
    {
        throw std::runtime_error("File not found");
    }

    json j;
    file >> j;
    if (!game){
        qDebug() << QString("game instance is null");
    }
    if (!gui){
        qDebug() << QString("gui instance is null");
   
    }
    this->game->setBoard(j);
}


// void GameController::loadBoard(const std::vector<Tile *> &tiles)
// {
//     game->setBoard(tiles);
//     gui->setBoard(game->getBoard());
// }

void GameController::start()
{
    game->addObserver(this);
    gui->showMenu();
}

std::vector<const Player *> GameController::getPlayers() const
{
    return game->getPlayers();
}

const Tile *GameController::getPlayerTile(const Player &player) const
{
    return game->getPlayerTile(player);
}


std::vector<const Tile *> GameController::getBoard() const{
    return game->getBoard();
};

const Player &GameController::getCurrentPlayer() const{
    return game->getCurrentPlayer();
};

 Player *const&GameController::getCurrentPlayerPtr() const{
    return game->getCurrentPlayerPtr();
};

void GameController::startGame(){
    game->startGame();
}

void GameController::rollDice(const Player &player){
    game->RollDice(player);
}

void GameController::buyProperty(const Player &player, const Tile &tile){
    game->buyProperty(player, tile);
}

void GameController::buyHouse(const Player &player, const Tile &tile){
    game->buyHouse(player, tile);
}

void GameController::buyHotel(const Player &player, const Tile &tile){
    game->buyHotel(player, tile);
}

void GameController::payBail(const Player &player){
    game->payBail(player);
}

void GameController::endTurn(const Player &player){
    game->endTurn(player);
}

void GameController::onNotify(const Event &event) {
    EventType type = event.getType();

    switch (type) {
    case EventType::PlayerPositionChanged:
        // Handle PlayerPositionChanged
        break;

    case EventType::PlayerRolledDice: {
        // Perform dynamic_cast and check if it succeeds
        const PlayerRolledDiceEvent* rolledDiceEvent = dynamic_cast<const PlayerRolledDiceEvent*>(&event);
        if (rolledDiceEvent) {
            gui->addBoardMessage("Player " + rolledDiceEvent->player.getName() +
                                 " rolled " + std::to_string(rolledDiceEvent->dice1) +
                                 " and " + std::to_string(rolledDiceEvent->dice2));
        }
        break;
    }

        // Handle other cases
    case EventType::PlayerIsInJail:{
        const PlayerIsInJailEvent* inJailEvent = dynamic_cast<const PlayerIsInJailEvent*>(&event);
        if (inJailEvent){
            gui->addBoardMessage("Player " + inJailEvent->player.getName() + " is in jail");
            gui->updatePlayerPosition(inJailEvent->player);
        }
        break;
    }
    case EventType::PlayerIsOutOfJailEvent:
    case EventType::PlayerRolledDoubles:
    case EventType::PlayerBoughtProperty:
    case EventType::PlayerBoughtHouse:
    case EventType::PlayerBoughtHotel:
    case EventType::PlayerPaidBail:
    case EventType::PlayerBankrupt:
    case EventType::PlayerWon:
    case EventType::PlayerLost:
    case EventType::PlayerTurnStart:
    case EventType::PlayerTurnEnd:
        break;
    }
}



