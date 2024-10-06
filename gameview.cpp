#include "gameview.h"
#include "ui_gamewindow.h"
#include "widgets.h"
#include "gamecontroller.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QLabel>

GameView::GameView(GameController *controller, QWidget *parent)
    : QWidget{parent}, controller(controller) {
    menuWindow = new MainWindow();
    mainGameWindow = new GameWindow();
    message_board = mainGameWindow->ui->message_board;
    board_layout = mainGameWindow->ui->board_layout;
    players_widgets_layout = mainGameWindow->ui->players_widget_layout;
    buyPropertyButton = mainGameWindow->ui->buyProperty;
    rollDiceButton = mainGameWindow->ui->rollDice;
    endTurnButton = mainGameWindow->ui->endTurn;
    jailBailButton = mainGameWindow->ui->jailBail;

    setupConnections();
}

void GameView::setupConnections() {
    // Connect menu actions
    connect(menuWindow, &MainWindow::startGame, this, &GameView::startNewGame);
    connect(menuWindow, &MainWindow::quitGame, this, &GameView::quitGame);

    // Button actions now retrieve the player from GameView
    connect(buyPropertyButton, &QPushButton::clicked, this, [=]() {
        const Player &currentPlayer = getCurrentPlayer();
        const Tile &tile = *(controller->getPlayerTile(currentPlayer));

        try {
            controller->buyProperty(currentPlayer, tile);
        } catch (const std::exception &e) {
            showErrorMessage(e.what());
        }
    });

    connect(rollDiceButton, &QPushButton::clicked, this, [=]() {
        try {
            const Player &currentPlayer = getCurrentPlayer();
            controller->rollDice(currentPlayer);
            updatePlayersDetails();
        } catch (const std::exception &e) {
            showErrorMessage(e.what());
        }
    });

    connect(endTurnButton, &QPushButton::clicked, this, [=]() {
        try {
            controller->endTurn(getCurrentPlayer());
            this->updateCurrentPlayer();
        } catch (const std::exception &e) {
            showErrorMessage(e.what());
        }
    });

    connect(jailBailButton, &QPushButton::clicked, this, [=]() {
        try {
            controller->payBail(getCurrentPlayer());
        } catch (const std::exception &e) {
            showErrorMessage(e.what());
        }
    });
}

void GameView::showMenu() {
    menuWindow->show();
}

void GameView::showErrorMessage(const std::string &message) {
    QMessageBox msgBox;
    msgBox.critical(0, "Error", QString::fromStdString(message));
    msgBox.setFixedSize(500, 200);
}

void GameView::startNewGame(int numOfPlayers) {
    qDebug() << QString("Starting new game with %1 players").arg(numOfPlayers);

    try {
        controller->loadBoard(DEFUALT_JSON_PATH);
        boardReference = controller->getBoard();
    } catch (std::exception &e) {
        showErrorMessage(e.what());
        return;
    }

    menuWindow->hide();

    for (int i = 0; i < numOfPlayers; i++) {
        try {
            addPlayer();
        } catch (std::exception &e) {
            showErrorMessage(e.what());
        }
    }

    setMainGameWindow();
    mainGameWindow->showMaximized();
}

void GameView::setBoard(std::vector<const Tile *> tiles) {
    if (tiles.size() != BOARD_SIZE) {
        showErrorMessage("Board size does not match the expected size of 40.");
        return;
    }

    tiles_widgets.reserve(BOARD_SIZE);

    for (int i = 0; i < tiles.size(); i++) {
        int position = tiles[i]->getId() - 1;
        int row, col;

        // Calculate row and column based on the tile's position
        if (position < TOP_ROW) {
            row = 0;
            col = position;
        } else if (position < RIGHT_COLUMN) {
            row = position - TOP_ROW;
            col = TOP_ROW;
        } else if (position < BOTTOM_ROW) {
            row = TOP_ROW;
            col = TOP_ROW - (position - RIGHT_COLUMN);
        } else {
            row = TOP_ROW - (position - BOTTOM_ROW);
            col = 0;
        }

        // Clear existing widget and add the new one
        QWidget *existingWidget = board_layout->itemAtPosition(row, col) ? board_layout->itemAtPosition(row, col)->widget() : nullptr;
        if (existingWidget) {
            board_layout->removeWidget(existingWidget);
            delete existingWidget;
        }

        TileWidget *tile_widget = new TileWidget(tiles[i]);
        tiles_widgets.push_back(tile_widget);
        board_layout->addWidget(tile_widget, row, col);
    }
}

void GameView::quitGame() {
    QApplication::quit();
}

void GameView::addPlayer() {
    while (true) {
        bool ok;
        QString name = QInputDialog::getText(nullptr, "Enter Name", "Please enter Player name:", QLineEdit::Normal, "", &ok);

        if (ok && !name.isEmpty()) {
            try {
                players.push_back(&(controller->addPlayer(name.toStdString())));
                break;
            } catch (std::exception &e) {
                showErrorMessage(e.what());
            }
        } else {
            qDebug() << QString("Player name not provided , please enter a name");
        }
    }
}

void GameView::setPlayers() {
    players_tokens.clear();
    players_tokens.reserve(players.size());
    players_widgets.clear();
    players_widgets.reserve(players.size());

    for (size_t i = 0; i < players.size(); i++) {
        const Player *player = players[i];

        PlayerWidget *player_widget = new PlayerWidget(*player, &players_colors[i], this);
        players_widgets.push_back(player_widget);
        players_widgets_layout->insertWidget(i, player_widget);

        QLabel *label = new QLabel(mainGameWindow);
        QPalette palette;
        palette.setColor(QPalette::Window, players_colors[i]);
        label->setAutoFillBackground(true);
        label->setPalette(palette);

        players_tokens.push_back(label);
        updatePlayerPosition(*player);
    }
}

void GameView::setMainGameWindow() {
    setBoard(boardReference);
    setupTilesConnections();
    setPlayers();
    controller->startGame();
    setCurrentPlayer(controller->getCurrentPlayerPtr());
    updateCurrentPlayer();
}

void GameView::updatePlayerPosition(const Player &player) {
    int position = player.getPosition();
    TileWidget *tileWidget = tiles_widgets[position];
    tileWidget->placePlayer(players_tokens[player.getID() - 1]);
    tileWidget->update();
}

void GameView::setCurrentPlayer(Player *const &player) {
    current_player = &player;
}

void GameView::addBoardMessage(const std::string &message) {
    message_board->setText(message_board->toPlainText() + QString::fromStdString(message) + "\n");
}

void GameView::updatePlayersDetails() {
    for (size_t i = 0; i < players.size(); i++) {
        players_widgets[i]->update_details();
        updatePlayerPosition(*players[i]);
    }
}

const Player &GameView::getCurrentPlayer() const {
    return **current_player;
}

void GameView::buyHouse(const Tile *tile)
{
    // Handle the action for buying a house on the given tile
    qDebug() << QString("Buying House on tile: %1").arg(tile->getName().c_str());
    // Add the actual game logic here
}

void GameView::buyHotel(const Tile *tile)
{
    // Handle the action for buying a house on the given tile
    qDebug() << QString("Buying Hotel on tile: %1").arg(tile->getName().c_str());
    // Add the actual game logic here
}

void GameView::setupTilesConnections()
{
    for (TileWidget *tileWidget : tiles_widgets) {
        TileDetailsWidget *detailsWidget = tileWidget->getTileDetails();

        if(detailsWidget){
        // Connect the signal to the GameView's slot
        connect(detailsWidget, &TileDetailsWidget::buyHouse, this, &GameView::buyHouse);
        connect(detailsWidget, &TileDetailsWidget::buyHotel, this, &GameView::buyHotel);

        }
        }
}

void GameView::updateCurrentPlayer(){
    this->mainGameWindow->ui->currentPlayer->setText(QString((*current_player)->getName().c_str()));
};
