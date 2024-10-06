#include "widgets.h"
#include "TileDetailsWidget.h"
#include "ui_tilewidget.h"
#include <QFile>
#include <qdialog.h>



TileWidget::TileWidget(const Tile *tile, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TileWidget)
{
    ui->setupUi(this);

    image = ui->image_or_details;
    name = ui->name;
    player_layout = ui->PlayersHolder;
    price = ui->price;
    details = nullptr;
    price->hide();
    // details_button->hide();
    if (const Utility *util = dynamic_cast<const Utility *>(tile)){
        setTilePicture(QString::fromStdString(tile->getName()).replace(" ","_"));
    }
    else{
    setTilePicture(QString::fromStdString(tile->getType()));
    };
    name->setText(QString(tile->getName().c_str()));
    details = new TileDetailsWidget(*tile);

    QString stylesheet;
    if (const Property *property = dynamic_cast<const Property *>(tile))
    {
        price->setText(QString::number(property->getPrice()));
        // QColor groupColor = groups[property->getGroup()-1];
        // stylesheet = QString("background-color: rgb(%1, %2, %3);color: black;")
        //                          .arg(groupColor.red())
        //                          .arg(groupColor.green())
        //                          .arg(groupColor.blue());

        // name->setStyleSheet(stylesheet);

        changeButtonAppearance(name,groups[property->getGroup()-1],Qt::black);
    }

else {
    QColor groupColor = groups.back();
    stylesheet = QString("background-color: rgb(%1, %2, %3);color: black;")
                             .arg(groupColor.red())
                             .arg(groupColor.green())
                             .arg(groupColor.blue());

    name->setStyleSheet(stylesheet);
}
    connect(name, &QPushButton::clicked, this, [=](){
        showDetails();
    });
}

TileWidget::~TileWidget()
{
    delete ui;
}

TileDetailsWidget *TileWidget::getTileDetails() const {
    return details;
};

void TileWidget::setTilePicture(const QString &tileName){
    QString image_path = ":/images/res/" + tileName.toLower() + ".png";

    if(QFile::exists(image_path)){
        QPixmap pix(image_path);
        image->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    }

    else {
        qDebug() << QString("Image for %1 not found").arg(tileName);
        image->setText("Image not available");
    }
};

QString TileWidget::getTileName() const{
    return name->text();
}

// QString TileWidget::getTileDetails() const{
//     return details;
// }

void TileWidget::placePlayer(QLabel *player){
    player_layout->addWidget(player);
}

void TileWidget::showDetails()
{
    static QDialog *dialog = nullptr;
    static TileDetailsWidget *currentDetailsWidget = nullptr;  // Pointer to track the current details widget

    // Create the dialog if it's not already created
    if (!dialog) {
        dialog = new QDialog(this);
        dialog->setWindowTitle("Tile Details");
        dialog->setFixedSize(350, 500);
    }

    // If a details widget is already showing, remove it from the layout without deleting it
    if (currentDetailsWidget) {
        dialog->layout()->removeWidget(currentDetailsWidget);
        currentDetailsWidget->hide();  // Hide the previous widget, keep it alive
    }

    // Set the current details widget to this tile's details widget
    currentDetailsWidget = this->details;
    currentDetailsWidget->update();  // Update the details widget content
    if(!currentDetailsWidget){
        return;
    }
    // Add the new details widget (the one belonging to this TileWidget)
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(dialog->layout());
    if (!layout) {
        layout = new QVBoxLayout(dialog);
        dialog->setLayout(layout);
    }
    layout->addWidget(currentDetailsWidget);
    currentDetailsWidget->show();  // Ensure the new widget is shown

    // Show the dialog with the updated content
    dialog->show();
    dialog->raise();  // Bring to the front
    dialog->activateWindow();  // Focus the window
}



void TileWidget::update(){
    // if (Property *property = dynamic_cast<Property *>(tile))
    // {
    //     property->setOwner(new Player("Player"));
    // }
}


PlayerWidget::PlayerWidget(const Player &player,QColor *color,QWidget *parent)
    : QWidget(parent),player(&player)
    , ui(new Ui::PlayerWidget){
    ui->setupUi(this);

    name = ui->name;
    money = ui->money;
    token = ui->token;

    name->setText(QString(player.getName().c_str()));
    money->setText(QString::number(player.getBalance()));

    if (color){
        QPalette p = token->palette();
        p.setColor(QPalette::ColorRole::Window,*color);
        token->setAutoFillBackground(true);
        token->setPalette(p);
    }

}

PlayerWidget::~PlayerWidget()
{
    delete ui;
}
