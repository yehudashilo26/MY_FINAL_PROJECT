/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalButtonLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *VerticalButtonsLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *NewGameButton;
    QPushButton *QuitButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    border-image: url(:/images/res/monopoly_logo.png) 0 0 0 0 stretch stretch;\n"
"    }"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalButtonLayout = new QHBoxLayout();
        horizontalButtonLayout->setObjectName("horizontalButtonLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalButtonLayout->addItem(horizontalSpacer);

        VerticalButtonsLayout = new QVBoxLayout();
        VerticalButtonsLayout->setObjectName("VerticalButtonsLayout");
        VerticalButtonsLayout->setContentsMargins(-1, 200, -1, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        VerticalButtonsLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimumSize(QSize(60, 30));
        spinBox->setMinimum(2);
        spinBox->setMaximum(8);

        horizontalLayout->addWidget(spinBox);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        VerticalButtonsLayout->addLayout(horizontalLayout);

        NewGameButton = new QPushButton(centralwidget);
        NewGameButton->setObjectName("NewGameButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(NewGameButton->sizePolicy().hasHeightForWidth());
        NewGameButton->setSizePolicy(sizePolicy1);

        VerticalButtonsLayout->addWidget(NewGameButton);

        QuitButton = new QPushButton(centralwidget);
        QuitButton->setObjectName("QuitButton");
        sizePolicy1.setHeightForWidth(QuitButton->sizePolicy().hasHeightForWidth());
        QuitButton->setSizePolicy(sizePolicy1);

        VerticalButtonsLayout->addWidget(QuitButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        VerticalButtonsLayout->addItem(verticalSpacer_2);

        VerticalButtonsLayout->setStretch(0, 16);
        VerticalButtonsLayout->setStretch(2, 1);
        VerticalButtonsLayout->setStretch(3, 1);
        VerticalButtonsLayout->setStretch(4, 4);

        horizontalButtonLayout->addLayout(VerticalButtonsLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalButtonLayout->addItem(horizontalSpacer_2);

        horizontalButtonLayout->setStretch(0, 3);
        horizontalButtonLayout->setStretch(1, 1);
        horizontalButtonLayout->setStretch(2, 3);

        verticalLayout->addLayout(horizontalButtonLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Number Of Players", nullptr));
        NewGameButton->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        QuitButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
