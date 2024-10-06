/********************************************************************************
** Form generated from reading UI file 'TileDetailsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILEDETAILSWIDGET_H
#define UI_TILEDETAILSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TileDetailsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QVBoxLayout *details_layout;
    QLabel *owner;
    QLabel *numofhouses;
    QLabel *hotel;
    QLabel *details;
    QSpacerItem *verticalSpacer;
    QLabel *cost;
    QPushButton *buyHouse;
    QPushButton *buyHotel;

    void setupUi(QWidget *TileDetailsWidget)
    {
        if (TileDetailsWidget->objectName().isEmpty())
            TileDetailsWidget->setObjectName("TileDetailsWidget");
        TileDetailsWidget->resize(488, 493);
        verticalLayout = new QVBoxLayout(TileDetailsWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(TileDetailsWidget);
        name->setObjectName("name");
        name->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(name);

        details_layout = new QVBoxLayout();
        details_layout->setObjectName("details_layout");
        owner = new QLabel(TileDetailsWidget);
        owner->setObjectName("owner");
        owner->setAlignment(Qt::AlignmentFlag::AlignCenter);

        details_layout->addWidget(owner);

        numofhouses = new QLabel(TileDetailsWidget);
        numofhouses->setObjectName("numofhouses");
        numofhouses->setAlignment(Qt::AlignmentFlag::AlignCenter);

        details_layout->addWidget(numofhouses);

        hotel = new QLabel(TileDetailsWidget);
        hotel->setObjectName("hotel");
        hotel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        details_layout->addWidget(hotel);

        details = new QLabel(TileDetailsWidget);
        details->setObjectName("details");
        details->setAlignment(Qt::AlignmentFlag::AlignCenter);

        details_layout->addWidget(details);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        details_layout->addItem(verticalSpacer);

        cost = new QLabel(TileDetailsWidget);
        cost->setObjectName("cost");
        cost->setAlignment(Qt::AlignmentFlag::AlignCenter);

        details_layout->addWidget(cost);


        verticalLayout->addLayout(details_layout);

        buyHouse = new QPushButton(TileDetailsWidget);
        buyHouse->setObjectName("buyHouse");

        verticalLayout->addWidget(buyHouse);

        buyHotel = new QPushButton(TileDetailsWidget);
        buyHotel->setObjectName("buyHotel");

        verticalLayout->addWidget(buyHotel);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 6);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        retranslateUi(TileDetailsWidget);

        QMetaObject::connectSlotsByName(TileDetailsWidget);
    } // setupUi

    void retranslateUi(QWidget *TileDetailsWidget)
    {
        TileDetailsWidget->setWindowTitle(QCoreApplication::translate("TileDetailsWidget", "Form", nullptr));
        name->setText(QString());
        owner->setText(QCoreApplication::translate("TileDetailsWidget", "Owner", nullptr));
        numofhouses->setText(QCoreApplication::translate("TileDetailsWidget", "# of Houses", nullptr));
        hotel->setText(QCoreApplication::translate("TileDetailsWidget", "Have Hotel", nullptr));
        details->setText(QCoreApplication::translate("TileDetailsWidget", "Details", nullptr));
        cost->setText(QCoreApplication::translate("TileDetailsWidget", "cost", nullptr));
        buyHouse->setText(QCoreApplication::translate("TileDetailsWidget", "Buy House", nullptr));
        buyHotel->setText(QCoreApplication::translate("TileDetailsWidget", "Buy Hotel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TileDetailsWidget: public Ui_TileDetailsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILEDETAILSWIDGET_H
