#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    board_layout = ui->board_layout;
}

GameWindow::~GameWindow()
{
    delete ui;
}





