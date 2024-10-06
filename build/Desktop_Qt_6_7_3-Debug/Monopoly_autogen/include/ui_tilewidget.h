/********************************************************************************
** Form generated from reading UI file 'tilewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILEWIDGET_H
#define UI_TILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *PlayersHolder;
    QPushButton *name;
    QLabel *image_or_details;
    QLabel *price;

    void setupUi(QWidget *TileWidget)
    {
        if (TileWidget->objectName().isEmpty())
            TileWidget->setObjectName("TileWidget");
        TileWidget->resize(362, 404);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TileWidget->sizePolicy().hasHeightForWidth());
        TileWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(TileWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PlayersHolder = new QHBoxLayout();
        PlayersHolder->setObjectName("PlayersHolder");
        PlayersHolder->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);

        verticalLayout->addLayout(PlayersHolder);

        name = new QPushButton(TileWidget);
        name->setObjectName("name");
        name->setMouseTracking(false);
        name->setCheckable(false);

        verticalLayout->addWidget(name);

        image_or_details = new QLabel(TileWidget);
        image_or_details->setObjectName("image_or_details");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(image_or_details->sizePolicy().hasHeightForWidth());
        image_or_details->setSizePolicy(sizePolicy1);
        image_or_details->setPixmap(QPixmap(QString::fromUtf8(":/images/res/electricCompany.png")));
        image_or_details->setScaledContents(true);

        verticalLayout->addWidget(image_or_details);

        price = new QLabel(TileWidget);
        price->setObjectName("price");
        price->setEnabled(false);
        price->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(price);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 8);
        verticalLayout->setStretch(3, 1);

        retranslateUi(TileWidget);

        QMetaObject::connectSlotsByName(TileWidget);
    } // setupUi

    void retranslateUi(QWidget *TileWidget)
    {
        TileWidget->setWindowTitle(QCoreApplication::translate("TileWidget", "Form", nullptr));
        name->setText(QCoreApplication::translate("TileWidget", "TelAviv", nullptr));
        image_or_details->setText(QString());
        price->setText(QCoreApplication::translate("TileWidget", "Price : 220$", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TileWidget: public Ui_TileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILEWIDGET_H
