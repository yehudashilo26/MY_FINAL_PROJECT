/********************************************************************************
** Form generated from reading UI file 'PlayerWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERWIDGET_H
#define UI_PLAYERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *name;
    QLabel *money;
    QLabel *token;

    void setupUi(QWidget *PlayerWidget)
    {
        if (PlayerWidget->objectName().isEmpty())
            PlayerWidget->setObjectName("PlayerWidget");
        PlayerWidget->resize(399, 100);
        PlayerWidget->setMaximumSize(QSize(400, 100));
        horizontalLayout = new QHBoxLayout(PlayerWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(PlayerWidget);
        name->setObjectName("name");
        name->setMinimumSize(QSize(150, 0));
        name->setAutoFillBackground(true);
        name->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(name);

        money = new QLabel(PlayerWidget);
        money->setObjectName("money");
        money->setMinimumSize(QSize(150, 0));
        money->setAutoFillBackground(true);
        money->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(money);

        token = new QLabel(PlayerWidget);
        token->setObjectName("token");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(token->sizePolicy().hasHeightForWidth());
        token->setSizePolicy(sizePolicy);
        token->setMinimumSize(QSize(0, 0));
        token->setAutoFillBackground(true);
        token->setScaledContents(false);
        token->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(token);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 2);

        retranslateUi(PlayerWidget);

        QMetaObject::connectSlotsByName(PlayerWidget);
    } // setupUi

    void retranslateUi(QWidget *PlayerWidget)
    {
        PlayerWidget->setWindowTitle(QCoreApplication::translate("PlayerWidget", "Form", nullptr));
        name->setText(QCoreApplication::translate("PlayerWidget", "TextLabel", nullptr));
        money->setText(QCoreApplication::translate("PlayerWidget", "TextLabel", nullptr));
        token->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlayerWidget: public Ui_PlayerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERWIDGET_H
