#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <qapplication.h>
#include <qtextedit.h>
#include "GameWindow.h"
#include "mainwindow.h"

// #include "GameControllerWrapper.h"
#define DEFUALT_JSON_PATH "../../board.json"

class GameController;
class GameView : public QWidget {
    Q_OBJECT

public:
    explicit GameView(GameController *contoller,QWidget *parent = nullptr);

    ~GameView() {
        delete mainGameWindow;
        delete menuWindow;
    }

    void showMenu();
    void updateGameUI(const QString &message);

private:
    GameWindow* mainGameWindow;
    MainWindow* menuWindow;
    GameController* controller;
    QGridLayout *board_layout;
    QVBoxLayout *players_widgets_layout;
    QPushButton *rollDiceButton;
    QPushButton *jailBailButton;
    QPushButton *endTurnButton;
    QPushButton *buyPropertyButton;
    QTextEdit *message_board;

    std::vector<TileWidget *> tiles_widgets;
    std::vector<const Tile *> boardReference;
    std::vector<const Player*> players;
    std::vector<PlayerWidget *> players_widgets;
    std::vector<QLabel *> players_tokens;
    Player * const* current_player;

    // Method to establish connections and manage signal-slot communication
    void setBoard(std::vector<const Tile *> tiles);
    void setMainGameWindow();
    void setupConnections();
    void setupTilesConnections();
    void showErrorMessage(const std::string &message);
    void addBoardMessage(const std::string &message);
    void addPlayer();
    void setPlayers();
    void updatePlayerPosition(const Player &player);
    void setCurrentPlayer(Player * const &player);
    void updatePlayersDetails();
    void updateCurrentPlayer();
    const Player &getCurrentPlayer() const;
    // Slot to quit the game and exit the application
    private slots:
        // void updatePlayer(std::string name,int balance,int position);
        void buyHouse(const Tile* tile);
        void buyHotel(const Tile* tile);
        void startNewGame(int numOfPlayers);
        void quitGame();



        friend class GameController;

};

#endif // GAMEVIEW_H
