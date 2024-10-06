#ifndef MONOPOLY_H
#define MONOPOLY_H

#include "player.h"
#include "json.hpp"
#include "tile.h"
#include "gameobserver.h"
using json = nlohmann::json;

class GameController; // Forward declaration of GameController class

#define BOARD_SIZE 40
#define START_BALANCE 1500
#define MAX_PLAYERS 8
#define MAX_HOUSES 4
#define MAX_HOTELS 1
#define MAX_DOUBLES 3
#define JAIL_BAIL 50
#define HOTEL_ADDITION 100

class Monopoly
{

private:
    std::vector<GameObserver *> observers;        // Vector of observers
    std::vector<Player> players;              // Vector of players
    std::vector<std::unique_ptr<Tile>> board; // Vector of tiles
    std::map<size_t, std::vector<Property *>> properties_groups;  // Map of properties
    Player *currentPlayer;
    Player *winner;

    // helper variables
    size_t jailIndex = 0;
    size_t goIndex = 0;
    bool isGameStarted = false;
    bool gameEnded = false;
    bool hasPlayerRolled = false;
    bool hasPlayerRolledDoubles = false;
    int doublesCount = 0;

    void notify(const Event &event); // Notify all observers of an event
    void setBoard(std::vector<Tile *> board); // Set the board
    void setBoard(const json &board);         // Set the board from JSON

    void checkPlayerTurn(const Player &player);
    void checkPlayerCanRoll(const Player &player);
    void checkPlayerRolled(const Player &player);
    void notifyObservers(const Event& event);
    Tile *getModifiableTile(const Tile *tile);



    // helper functions

    friend class GameController; // Only GameController can access private members and methods

    // Private Singleton access method
    Monopoly();                // Private constructor (only accessible by GameController)
    ~Monopoly();               // Private destructor
    static Monopoly *instance; // Singleton instance of Monopoly
    static Monopoly *getInstance();

public:
    // Delete copy constructor and assignment operator to prevent copying
    Monopoly(const Monopoly &) = delete;
    Monopoly &operator=(const Monopoly &) = delete;
    void addObserver(GameObserver* observer);
    
    
    void startGame();
    // actions functions
    void RollDice(const Player &player);
    void buyProperty(const Player &player, const Tile &tile);
    void buyHouse(const Player &player, const Tile &tile);
    void buyHotel(const Player &player, const Tile &tile);
    void payBail(const Player &player);
    void endTurn(const Player &player);

    // Getters
    const Player &getCurrentPlayer(); // Get the current player
    Player *const &getCurrentPlayerPtr();
    const Tile *getPlayerTile(const Player &player) const;
    const Player &getPlayerByName(const std::string &name);
    const Player &addPlayer(const std::string &name); // Add a player
    
    // inner logic functions to let tile do operations under the game manager.
    void payPlayer(Player &player, Player &owner, int amount);
    void payBank(Player &player, int amount);
    void movePlayer(Player &player, int spaces);
    void nextPlayer();
    void moveToJail(Player &player);
    void moveOutOfJail(Player &player);

    std::vector<const Tile *> getBoard() const;
    std::vector<const Player *> getPlayers() const;
    
    
    friend class GameController;
};

#endif // MONOPOLY_H
