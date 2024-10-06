#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gameobserver.h"
#include "monopoly.h"
#include "gameview.h"

#include "json.hpp"
using json = nlohmann::json;

class GameController : public GameObserver
{
public:
    explicit GameController();
    void onNotify(const Event &event) override;
    
    const Player &addPlayer(const std::string &name);
    const Tile *getPlayerTile(const Player &player) const;
    
    void loadBoard(const std::string &json_path);
    void loadBoard(const std::vector<Tile *> &tiles);
    void startGame();
    void start();
    
    void rollDice(const Player &player);
    void buyProperty(const Player &player, const Tile &tile);
    void buyHouse(const Player &player, const Tile &tile);
    void buyHotel(const Player &player, const Tile &tile);
    void payBail(const Player &player);
    void endTurn(const Player &player);

    std::vector<const Tile *> getBoard() const;
    std::vector<const Player *> getPlayers() const;
    const Player &getCurrentPlayer() const;
    Player * const& getCurrentPlayerPtr() const;
private:
    Monopoly *game;
    GameView *gui;

};

#endif // GAMECONTROLLER_H
