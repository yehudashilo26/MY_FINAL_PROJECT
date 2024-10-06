#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "tile.h"
#include "widgets.h"
#include <QMainWindow>
#include <qgridlayout.h>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    QGridLayout *board_layout;
    std::map<Tile *, TileWidget *> board;
    std::map<Player *, PlayerWidget *> playerWidgets;
    std::map<Player *, QLabel *> playerTokens;
    TileWidget *createTileWidget(Tile *tile);
    PlayerWidget *createPlayerWidget(Player *player);


    void setupConnections();

    friend class GameView;
};


#endif // GAMEWINDOW_H
