#ifndef PLAYERTOKEN_H
#define PLAYERTOKEN_H

#include <QWidget>

namespace Ui {
class PlayerToken;
}

class PlayerToken : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerToken(QWidget *parent = nullptr);
    ~PlayerToken();

private:
    Ui::PlayerToken *ui;
};

#endif // PLAYERTOKEN_H
