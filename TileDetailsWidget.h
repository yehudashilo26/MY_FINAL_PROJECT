#ifndef TILEDETAILSWIDGET_H
#define TILEDETAILSWIDGET_H

#include "tile.h"
#include <QWidget>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

namespace Ui {
class TileDetailsWidget;
}

class TileDetailsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TileDetailsWidget(const Tile& tile, QWidget *parent = nullptr);
    ~TileDetailsWidget();

    void update();

signals:
    void buyHouse(const Tile* tile);
    void buyHotel(const Tile* tile);

protected:
    Ui::TileDetailsWidget *ui;
    const Tile* tile;
    QLabel* name;
    QLabel* details;
    QLabel* cost;
    QLabel* owner;
    QLabel* houses;
    QLabel* hotel;
    QVBoxLayout* details_layout;
    QPushButton* buy_house;
    QPushButton* buy_hotel;
};


#endif // TILEDETAILSWIDGET_H
