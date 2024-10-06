#ifndef WIDGETS_H
#define WIDGETS_H

#include "TileDetailsWidget.h"
#include "tile.h"
#include "ui_PlayerWidget.h"
#include <QWidget>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

#define TOP_ROW 10
#define RIGHT_COLUMN 20
#define BOTTOM_ROW 30
#define MAX_TILES 40

static std::vector<QColor> players_colors = {
    QColor("crimson"),  // Crimson
    QColor("darkblue"),  // Dark Blue
    QColor("forestgreen"),  // Forest Green
    QColor("gold"),  // Gold
    QColor("darkcyan"),  // Dark Cyan
    QColor("darkmagenta"),  // Dark Magenta
    QColor("orangered"),  // Orange Red
    QColor("darkviolet")  // Dark Violet
};



static std::vector<QColor> groups = {
    QColor("lightcoral"),  // Light Coral
    QColor("palegoldenrod"),  // Pale Goldenrod
    QColor("lightseagreen"),  // Light Sea Green
    QColor("mediumorchid"),  // Medium Orchid
    QColor("sandybrown"),  // Sandy Brown
    QColor("lightsteelblue"),  // Light Steel Blue
    QColor("mediumaquamarine"),  // Medium Aquamarine
    QColor("khaki"),  // Khaki
    QColor("darkGray")  // Light Salmon (new color)
};



namespace Ui {
class TileWidget;
}

class TileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TileWidget(const Tile *tile, QWidget *parent = nullptr);

    virtual void showDetails();
    QString getTileName() const;
    TileDetailsWidget *getTileDetails() const;
    void placePlayer(QLabel *player);

    ~TileWidget();
    void update();

protected:
    Ui::TileWidget *ui;
    QLabel *image;
    QLabel *price;
    QPushButton *name;
    QHBoxLayout *player_layout;
    TileDetailsWidget *details;

    void setTilePicture(const QString &tileName);
};

class PlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerWidget(const Player &player, QColor *color=nullptr, QWidget *parent = nullptr);
    ~PlayerWidget();

    void update_details(){
        money->setText(QString::number(player->getBalance()));
    }

protected:
    Ui::PlayerWidget *ui;
    const Player *player;
    QLabel *name;
    QLabel *money;
    QLabel *token;
};


static void changeLabelColor(QLabel *label, const QColor &color) {
    QPalette palette;
    palette.setColor(QPalette::Window, color);
    label->setAutoFillBackground(true);
    label->setPalette(palette);
    label->update();
}



static void changeLabelTextColor(QLabel *label, const QColor &color) {
    QPalette palette = label->palette();
    palette.setColor(QPalette::WindowText, color);
    label->setPalette(palette);
    label->update();
}

static void changeButtonColor(QPushButton *button, const QColor &color) {
    // Set the background color using a style sheet
    button->setStyleSheet(QString("background-color: %1;").arg(color.name()));
}

static void changeButtonTextColor(QPushButton *button, const QColor &color) {
    // Set the text color using a style sheet
    button->setStyleSheet(button->styleSheet() + QString(" color: %1;").arg(color.name()));
}

static void changeButtonAppearance(QPushButton *button, const QColor &backgroundColor, const QColor &textColor) {
    button->setStyleSheet(QString("background-color: %1; color: %2;")
                              .arg(backgroundColor.name())
                              .arg(textColor.name()));
}

static void changeLabelAppearance(QLabel *label, const QColor &backgroundColor, const QColor &textColor) {
    label->setStyleSheet(QString("background-color: %1; color: %2;")
                              .arg(backgroundColor.name())
                              .arg(textColor.name()));
}

#endif // WIDGETS_H
