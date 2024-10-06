/********************************************************************************
** Form generated from reading UI file 'tempclass.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPCLASS_H
#define UI_TEMPCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tempclass
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *tempclass)
    {
        if (tempclass->objectName().isEmpty())
            tempclass->setObjectName("tempclass");
        tempclass->resize(800, 600);
        centralwidget = new QWidget(tempclass);
        centralwidget->setObjectName("centralwidget");
        tempclass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(tempclass);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        tempclass->setMenuBar(menubar);
        statusbar = new QStatusBar(tempclass);
        statusbar->setObjectName("statusbar");
        tempclass->setStatusBar(statusbar);

        retranslateUi(tempclass);

        QMetaObject::connectSlotsByName(tempclass);
    } // setupUi

    void retranslateUi(QMainWindow *tempclass)
    {
        tempclass->setWindowTitle(QCoreApplication::translate("tempclass", "tempclass", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tempclass: public Ui_tempclass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPCLASS_H
