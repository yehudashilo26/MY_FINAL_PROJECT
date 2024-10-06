/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *board_players_layout;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *board_layout;
    QWidget *tile_9;
    QWidget *tile_12;
    QWidget *tile_2;
    QWidget *tile_11;
    QWidget *tile_5;
    QWidget *tile_18;
    QWidget *tile_3;
    QWidget *tile_15;
    QWidget *tile_10;
    QWidget *tile_6;
    QWidget *tile_19;
    QWidget *tile_13;
    QWidget *tile_17;
    QWidget *tile_7;
    QWidget *tile_1;
    QWidget *tile_14;
    QWidget *tile_8;
    QWidget *tile_4;
    QWidget *tile_20;
    QWidget *tile_16;
    QWidget *tile_21;
    QWidget *tile_22;
    QWidget *tile_23;
    QWidget *tile_24;
    QWidget *tile_25;
    QWidget *tile_26;
    QWidget *tile_27;
    QWidget *tile_28;
    QWidget *tile_29;
    QWidget *tile_30;
    QWidget *tile_31;
    QWidget *tile_32;
    QWidget *tile_33;
    QWidget *tile_34;
    QWidget *tile_35;
    QWidget *tile_36;
    QWidget *tile_37;
    QWidget *tile_38;
    QWidget *tile_39;
    QWidget *tile_40;
    QLabel *image;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QVBoxLayout *players_widget_layout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLabel *currentPlayer;
    QWidget *widget;
    QHBoxLayout *action_layout;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QTextEdit *message_board;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_3;
    QPushButton *rollDice;
    QPushButton *endTurn;
    QPushButton *buyProperty;
    QPushButton *jailBail;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName("GameWindow");
        GameWindow->resize(800, 600);
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        board_players_layout = new QHBoxLayout();
        board_players_layout->setSpacing(0);
        board_players_layout->setObjectName("board_players_layout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        board_players_layout->addItem(horizontalSpacer_2);

        board_layout = new QGridLayout();
        board_layout->setSpacing(0);
        board_layout->setObjectName("board_layout");
        tile_9 = new QWidget(centralwidget);
        tile_9->setObjectName("tile_9");

        board_layout->addWidget(tile_9, 0, 8, 1, 1);

        tile_12 = new QWidget(centralwidget);
        tile_12->setObjectName("tile_12");

        board_layout->addWidget(tile_12, 1, 10, 1, 1);

        tile_2 = new QWidget(centralwidget);
        tile_2->setObjectName("tile_2");

        board_layout->addWidget(tile_2, 0, 1, 1, 1);

        tile_11 = new QWidget(centralwidget);
        tile_11->setObjectName("tile_11");

        board_layout->addWidget(tile_11, 0, 10, 1, 1);

        tile_5 = new QWidget(centralwidget);
        tile_5->setObjectName("tile_5");

        board_layout->addWidget(tile_5, 0, 4, 1, 1);

        tile_18 = new QWidget(centralwidget);
        tile_18->setObjectName("tile_18");

        board_layout->addWidget(tile_18, 7, 10, 1, 1);

        tile_3 = new QWidget(centralwidget);
        tile_3->setObjectName("tile_3");

        board_layout->addWidget(tile_3, 0, 2, 1, 1);

        tile_15 = new QWidget(centralwidget);
        tile_15->setObjectName("tile_15");

        board_layout->addWidget(tile_15, 4, 10, 1, 1);

        tile_10 = new QWidget(centralwidget);
        tile_10->setObjectName("tile_10");

        board_layout->addWidget(tile_10, 0, 9, 1, 1);

        tile_6 = new QWidget(centralwidget);
        tile_6->setObjectName("tile_6");

        board_layout->addWidget(tile_6, 0, 5, 1, 1);

        tile_19 = new QWidget(centralwidget);
        tile_19->setObjectName("tile_19");

        board_layout->addWidget(tile_19, 8, 10, 1, 1);

        tile_13 = new QWidget(centralwidget);
        tile_13->setObjectName("tile_13");

        board_layout->addWidget(tile_13, 2, 10, 1, 1);

        tile_17 = new QWidget(centralwidget);
        tile_17->setObjectName("tile_17");

        board_layout->addWidget(tile_17, 6, 10, 1, 1);

        tile_7 = new QWidget(centralwidget);
        tile_7->setObjectName("tile_7");

        board_layout->addWidget(tile_7, 0, 6, 1, 1);

        tile_1 = new QWidget(centralwidget);
        tile_1->setObjectName("tile_1");

        board_layout->addWidget(tile_1, 0, 0, 1, 1);

        tile_14 = new QWidget(centralwidget);
        tile_14->setObjectName("tile_14");

        board_layout->addWidget(tile_14, 3, 10, 1, 1);

        tile_8 = new QWidget(centralwidget);
        tile_8->setObjectName("tile_8");

        board_layout->addWidget(tile_8, 0, 7, 1, 1);

        tile_4 = new QWidget(centralwidget);
        tile_4->setObjectName("tile_4");

        board_layout->addWidget(tile_4, 0, 3, 1, 1);

        tile_20 = new QWidget(centralwidget);
        tile_20->setObjectName("tile_20");

        board_layout->addWidget(tile_20, 9, 10, 1, 1);

        tile_16 = new QWidget(centralwidget);
        tile_16->setObjectName("tile_16");

        board_layout->addWidget(tile_16, 5, 10, 1, 1);

        tile_21 = new QWidget(centralwidget);
        tile_21->setObjectName("tile_21");

        board_layout->addWidget(tile_21, 10, 10, 1, 1);

        tile_22 = new QWidget(centralwidget);
        tile_22->setObjectName("tile_22");

        board_layout->addWidget(tile_22, 10, 9, 1, 1);

        tile_23 = new QWidget(centralwidget);
        tile_23->setObjectName("tile_23");

        board_layout->addWidget(tile_23, 10, 8, 1, 1);

        tile_24 = new QWidget(centralwidget);
        tile_24->setObjectName("tile_24");

        board_layout->addWidget(tile_24, 10, 7, 1, 1);

        tile_25 = new QWidget(centralwidget);
        tile_25->setObjectName("tile_25");

        board_layout->addWidget(tile_25, 10, 6, 1, 1);

        tile_26 = new QWidget(centralwidget);
        tile_26->setObjectName("tile_26");

        board_layout->addWidget(tile_26, 10, 5, 1, 1);

        tile_27 = new QWidget(centralwidget);
        tile_27->setObjectName("tile_27");

        board_layout->addWidget(tile_27, 10, 4, 1, 1);

        tile_28 = new QWidget(centralwidget);
        tile_28->setObjectName("tile_28");

        board_layout->addWidget(tile_28, 10, 3, 1, 1);

        tile_29 = new QWidget(centralwidget);
        tile_29->setObjectName("tile_29");

        board_layout->addWidget(tile_29, 10, 2, 1, 1);

        tile_30 = new QWidget(centralwidget);
        tile_30->setObjectName("tile_30");

        board_layout->addWidget(tile_30, 10, 1, 1, 1);

        tile_31 = new QWidget(centralwidget);
        tile_31->setObjectName("tile_31");

        board_layout->addWidget(tile_31, 10, 0, 1, 1);

        tile_32 = new QWidget(centralwidget);
        tile_32->setObjectName("tile_32");

        board_layout->addWidget(tile_32, 9, 0, 1, 1);

        tile_33 = new QWidget(centralwidget);
        tile_33->setObjectName("tile_33");

        board_layout->addWidget(tile_33, 8, 0, 1, 1);

        tile_34 = new QWidget(centralwidget);
        tile_34->setObjectName("tile_34");

        board_layout->addWidget(tile_34, 7, 0, 1, 1);

        tile_35 = new QWidget(centralwidget);
        tile_35->setObjectName("tile_35");

        board_layout->addWidget(tile_35, 6, 0, 1, 1);

        tile_36 = new QWidget(centralwidget);
        tile_36->setObjectName("tile_36");

        board_layout->addWidget(tile_36, 5, 0, 1, 1);

        tile_37 = new QWidget(centralwidget);
        tile_37->setObjectName("tile_37");

        board_layout->addWidget(tile_37, 4, 0, 1, 1);

        tile_38 = new QWidget(centralwidget);
        tile_38->setObjectName("tile_38");

        board_layout->addWidget(tile_38, 3, 0, 1, 1);

        tile_39 = new QWidget(centralwidget);
        tile_39->setObjectName("tile_39");

        board_layout->addWidget(tile_39, 2, 0, 1, 1);

        tile_40 = new QWidget(centralwidget);
        tile_40->setObjectName("tile_40");

        board_layout->addWidget(tile_40, 1, 0, 1, 1);

        image = new QLabel(centralwidget);
        image->setObjectName("image");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setPixmap(QPixmap(QString::fromUtf8(":/images/res/monopoly_logo.png")));
        image->setScaledContents(true);

        board_layout->addWidget(image, 2, 2, 7, 7);

        board_layout->setRowStretch(0, 5);
        board_layout->setRowStretch(1, 5);
        board_layout->setRowStretch(2, 5);
        board_layout->setRowStretch(3, 5);
        board_layout->setRowStretch(4, 5);
        board_layout->setRowStretch(5, 5);
        board_layout->setRowStretch(6, 5);
        board_layout->setRowStretch(7, 5);
        board_layout->setRowStretch(8, 5);
        board_layout->setRowStretch(9, 5);
        board_layout->setRowStretch(10, 5);
        board_layout->setColumnStretch(0, 5);
        board_layout->setColumnStretch(1, 5);
        board_layout->setColumnStretch(2, 5);
        board_layout->setColumnStretch(3, 5);
        board_layout->setColumnStretch(4, 5);
        board_layout->setColumnStretch(5, 5);
        board_layout->setColumnStretch(6, 5);
        board_layout->setColumnStretch(7, 5);
        board_layout->setColumnStretch(8, 5);
        board_layout->setColumnStretch(9, 5);
        board_layout->setColumnStretch(10, 5);

        board_players_layout->addLayout(board_layout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        board_players_layout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setAutoFillBackground(true);
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setAutoFillBackground(true);
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAutoFillBackground(true);
        label_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout_3);

        players_widget_layout = new QVBoxLayout();
        players_widget_layout->setObjectName("players_widget_layout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        players_widget_layout->addItem(verticalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        players_widget_layout->addWidget(label);

        currentPlayer = new QLabel(centralwidget);
        currentPlayer->setObjectName("currentPlayer");
        currentPlayer->setAutoFillBackground(true);
        currentPlayer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        players_widget_layout->addWidget(currentPlayer);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");

        players_widget_layout->addWidget(widget);


        verticalLayout_2->addLayout(players_widget_layout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 20);

        board_players_layout->addLayout(verticalLayout_2);

        board_players_layout->setStretch(0, 1);
        board_players_layout->setStretch(1, 12);
        board_players_layout->setStretch(2, 1);
        board_players_layout->setStretch(3, 3);

        verticalLayout->addLayout(board_players_layout);

        action_layout = new QHBoxLayout();
        action_layout->setSpacing(0);
        action_layout->setObjectName("action_layout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        action_layout->addItem(horizontalSpacer_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setAutoFillBackground(true);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        message_board = new QTextEdit(centralwidget);
        message_board->setObjectName("message_board");
        message_board->setReadOnly(true);

        verticalLayout_3->addWidget(message_board);


        action_layout->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        action_layout->addItem(horizontalSpacer_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        rollDice = new QPushButton(centralwidget);
        rollDice->setObjectName("rollDice");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rollDice->sizePolicy().hasHeightForWidth());
        rollDice->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(rollDice, 0, 0, 1, 1);

        endTurn = new QPushButton(centralwidget);
        endTurn->setObjectName("endTurn");

        gridLayout_3->addWidget(endTurn, 1, 0, 1, 1);

        buyProperty = new QPushButton(centralwidget);
        buyProperty->setObjectName("buyProperty");
        sizePolicy1.setHeightForWidth(buyProperty->sizePolicy().hasHeightForWidth());
        buyProperty->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(buyProperty, 0, 1, 1, 1);

        jailBail = new QPushButton(centralwidget);
        jailBail->setObjectName("jailBail");

        gridLayout_3->addWidget(jailBail, 1, 1, 1, 1);


        action_layout->addLayout(gridLayout_3);

        action_layout->setStretch(0, 1);
        action_layout->setStretch(1, 12);
        action_layout->setStretch(2, 1);
        action_layout->setStretch(3, 3);

        verticalLayout->addLayout(action_layout);

        verticalLayout->setStretch(0, 8);
        verticalLayout->setStretch(1, 2);
        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "MainWindow", nullptr));
        image->setText(QString());
        label_3->setText(QCoreApplication::translate("GameWindow", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("GameWindow", "Money", nullptr));
        label_2->setText(QCoreApplication::translate("GameWindow", "Token", nullptr));
        label->setText(QCoreApplication::translate("GameWindow", "Current Player", nullptr));
        currentPlayer->setText(QCoreApplication::translate("GameWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("GameWindow", "MessageBoard", nullptr));
        rollDice->setText(QCoreApplication::translate("GameWindow", "Roll Dice", nullptr));
        endTurn->setText(QCoreApplication::translate("GameWindow", "End Turn", nullptr));
        buyProperty->setText(QCoreApplication::translate("GameWindow", "Buy Property", nullptr));
        jailBail->setText(QCoreApplication::translate("GameWindow", "Pay Jail Bail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
