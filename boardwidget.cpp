#include "ui_boardwidget.h"
#include "widgets.h"

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BoardWidget)
{
    ui->setupUi(this);

    // setBoard(tiles);
    // initBoardWidget();
}

BoardWidget::~BoardWidget()
{
    for (auto tile : board)
    {
        delete tile;
    }

    delete ui;
}

void BoardWidget::initBoardWidget()
{
    for (size_t i = 0; i < board.size(); i++)
    {
        QWidget *existingWidget = nullptr;
        // the grid is 11x11 the tiles are placed in a spiral pattern on the outer edge of the grid.
        // the first 10 tiles are the top row, the next 10 are the right column, the next 10 are the bottom row, and the next 10 are the left column.

        if (i < TOP_ROW) {
            existingWidget = ui->board->itemAtPosition(0, i) ? ui->board->itemAtPosition(0, i)->widget() : nullptr;
            if (existingWidget) {
                ui->board->removeWidget(existingWidget);
                delete existingWidget;
            }
            ui->board->addWidget(board[i], 0, i);
        }
        else if (i < RIGHT_COLUMN) {
            existingWidget = ui->board->itemAtPosition(i - TOP_ROW, TOP_ROW) ? ui->board->itemAtPosition(i - TOP_ROW, TOP_ROW)->widget() : nullptr;
            if (existingWidget) {
                ui->board->removeWidget(existingWidget);
                delete existingWidget;
            }
            ui->board->addWidget(board[i], i - TOP_ROW, TOP_ROW);
        }
        else if (i < BOTTOM_ROW) {
            existingWidget = ui->board->itemAtPosition(TOP_ROW, i - RIGHT_COLUMN) ? ui->board->itemAtPosition(TOP_ROW, i - RIGHT_COLUMN)->widget() : nullptr;
            if (existingWidget) {
                ui->board->removeWidget(existingWidget);
                delete existingWidget;
            }
            ui->board->addWidget(board[i], TOP_ROW, i - RIGHT_COLUMN);
        }
        else {
            existingWidget = ui->board->itemAtPosition(i - BOTTOM_ROW, 0) ? ui->board->itemAtPosition(i - BOTTOM_ROW, 0)->widget() : nullptr;
            if (existingWidget) {
                ui->board->removeWidget(existingWidget);
                delete existingWidget;
            }
            ui->board->addWidget(board[i], i - BOTTOM_ROW, 0);
        }
}
}

void BoardWidget::setBoard(std::vector<TileWidget*> tiles)
{
    if (tiles.size() != MAX_TILES)
    {
        throw std::invalid_argument("Board must have 40 tiles.");
    }

    board = tiles;
}


