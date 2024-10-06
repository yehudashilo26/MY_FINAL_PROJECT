#include "TileDetailsWidget.h"
#include "ui_TileDetailsWidget.h"
#include "widgets.h"

TileDetailsWidget::TileDetailsWidget(const Tile& parent_tile, QWidget *parent)
    : QWidget(parent), tile(&parent_tile)
{
    // Setup UI and common fields
    ui = new Ui::TileDetailsWidget;
    ui->setupUi(this);

    name = ui->name;
    details = ui->details;
    cost = ui->cost;
    owner = ui->owner;
    houses = ui->numofhouses;
    hotel = ui->hotel;
    details_layout = ui->details_layout;
    buy_house = ui->buyHouse;
    buy_hotel = ui->buyHotel;

    // init the details widget by the tile type;

    name->setText(parent_tile.getName().c_str());
    details->setText(parent_tile.getDetails().c_str());
    changeLabelAppearance(name,groups.back(),Qt::black);

    if (const Buyable *buyable = dynamic_cast<const Buyable *>(&parent_tile))
    {
        cost->setText(QString("Cost: ") +QString::number(buyable->getPrice()));
        owner->setText(buyable->getOwner() ? QString("Owner: ") + QString(buyable->getOwner()->getName().c_str()) : QString("Owner: ") +QString("None") );
        if (const Property *property = dynamic_cast<const Property *>(buyable))
        {
            changeLabelAppearance(name,groups[property->getGroup()-1],Qt::black);
            houses->setText(QString("Number of houses: ") + QString::number(property->getHouses()));
            hotel->setText(property->hasHotel() ? QString("Hotel : Yes") : QString("Hotel : No"));
            connect(buy_house, &QPushButton::clicked, this, [=](){
                emit buyHouse(tile);
            });
            connect(buy_hotel, &QPushButton::clicked, this, [=](){
                emit buyHotel(tile);
            });
        }
        else
        {
            houses->hide();
            hotel->hide();
            buy_house->hide();
            buy_hotel->hide();
        }
    }
    else
    {
        cost->hide();
        owner->hide();
        houses->hide();
        hotel->hide();
        buy_house->hide();
        buy_hotel->hide();
    }

}

void TileDetailsWidget::update()
{
    // Base class update logic
    name->setText(tile->getName().c_str());
    details->setText(tile->getDetails().c_str());

    if (const Buyable *buyable = dynamic_cast<const Buyable *>(tile))
    {
        cost->setText(QString("Cost: ") + QString::number(buyable->getPrice()));
        owner->setText(buyable->getOwner() ? QString("Owner: ") + QString(buyable->getOwner()->getName().c_str()) : QString("Owner: ") + QString("None"));

        if (const Property *property = dynamic_cast<const Property *>(buyable))
        {
            changeLabelAppearance(name, groups[property->getGroup() - 1], Qt::black);
            houses->setText(QString("Number of houses: ") + QString::number(property->getHouses()));
            hotel->setText(property->hasHotel() ? QString("Hotel : Yes") : QString("Hotel : No"));
        }
    }
}

TileDetailsWidget::~TileDetailsWidget()
{
    delete ui;
}

