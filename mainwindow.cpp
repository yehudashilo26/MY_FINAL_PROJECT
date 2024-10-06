#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons to emit signals
    connect(ui->NewGameButton, &QPushButton::clicked, this, [=](){
        emit startGame(ui->spinBox->value());  // Example: Emit with a fixed number of players
    });

    connect(ui->QuitButton, &QPushButton::clicked, this, &MainWindow::quitGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}
