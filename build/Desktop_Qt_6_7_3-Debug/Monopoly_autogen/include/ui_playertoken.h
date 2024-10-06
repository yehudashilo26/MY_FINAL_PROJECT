/********************************************************************************
** Form generated from reading UI file 'playertoken.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERTOKEN_H
#define UI_PLAYERTOKEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerToken
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *coin;

    void setupUi(QWidget *PlayerToken)
    {
        if (PlayerToken->objectName().isEmpty())
            PlayerToken->setObjectName("PlayerToken");
        PlayerToken->resize(990, 1000);
        PlayerToken->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(PlayerToken);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        coin = new QLabel(PlayerToken);
        coin->setObjectName("coin");
        coin->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        coin->setAutoFillBackground(false);
        coin->setPixmap(QPixmap(QString::fromUtf8(":/images/res/freeParking.png")));
        coin->setScaledContents(true);
        coin->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(coin);


        retranslateUi(PlayerToken);

        QMetaObject::connectSlotsByName(PlayerToken);
    } // setupUi

    void retranslateUi(QWidget *PlayerToken)
    {
        PlayerToken->setWindowTitle(QCoreApplication::translate("PlayerToken", "Form", nullptr));
        coin->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlayerToken: public Ui_PlayerToken {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERTOKEN_H
