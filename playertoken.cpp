#include "playertoken.h"
#include "ui_playertoken.h"

PlayerToken::PlayerToken(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayerToken)
{
    ui->setupUi(this);
}

PlayerToken::~PlayerToken()
{
    delete ui;
}
