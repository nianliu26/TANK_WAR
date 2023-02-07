/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "gamewidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *pageMainMenu;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *labTitle;
    QPushButton *btnSingleMode;
    QPushButton *pushButton;
    QWidget *pageChooseMap;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_5;
    QPushButton *btnStartGame;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *mapList;
    QLabel *labChooseMap;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btnComeBackToMainMenu;
    QWidget *pageLoading;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_8;
    QLabel *labLoading;
    QSpacerItem *verticalSpacer_7;
    QLabel *label;
    QPushButton *btnComeBackToChooseMap;
    QWidget *pageGame;
    QHBoxLayout *horizontalLayout;
    GameWidget *widgetGame;
    QWidget *pageGameOver;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labGameOver;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnGameOver;
    QSpacerItem *verticalSpacer_10;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(700, 500);
        Widget->setMinimumSize(QSize(0, 0));
        Widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        pageMainMenu = new QWidget();
        pageMainMenu->setObjectName("pageMainMenu");
        gridLayout = new QGridLayout(pageMainMenu);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        labTitle = new QLabel(pageMainMenu);
        labTitle->setObjectName("labTitle");
        labTitle->setMinimumSize(QSize(500, 100));
        labTitle->setMaximumSize(QSize(500, 100));
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        font.setItalic(true);
        labTitle->setFont(font);
        labTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labTitle, 1, 1, 1, 1);

        btnSingleMode = new QPushButton(pageMainMenu);
        btnSingleMode->setObjectName("btnSingleMode");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSingleMode->sizePolicy().hasHeightForWidth());
        btnSingleMode->setSizePolicy(sizePolicy);
        btnSingleMode->setMinimumSize(QSize(0, 0));
        btnSingleMode->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        btnSingleMode->setFont(font1);

        gridLayout->addWidget(btnSingleMode, 3, 1, 1, 1);

        pushButton = new QPushButton(pageMainMenu);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        stackedWidget->addWidget(pageMainMenu);
        pageChooseMap = new QWidget();
        pageChooseMap->setObjectName("pageChooseMap");
        gridLayout_3 = new QGridLayout(pageChooseMap);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 0, 1, 1, 1);

        btnStartGame = new QPushButton(pageChooseMap);
        btnStartGame->setObjectName("btnStartGame");

        gridLayout_3->addWidget(btnStartGame, 4, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        mapList = new QComboBox(pageChooseMap);
        mapList->setObjectName("mapList");

        gridLayout_3->addWidget(mapList, 3, 1, 1, 1);

        labChooseMap = new QLabel(pageChooseMap);
        labChooseMap->setObjectName("labChooseMap");
        labChooseMap->setMinimumSize(QSize(400, 100));
        labChooseMap->setMaximumSize(QSize(400, 100));
        QFont font2;
        font2.setPointSize(30);
        font2.setBold(false);
        font2.setItalic(false);
        labChooseMap->setFont(font2);
        labChooseMap->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labChooseMap, 1, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 6, 1, 1, 1);

        btnComeBackToMainMenu = new QPushButton(pageChooseMap);
        btnComeBackToMainMenu->setObjectName("btnComeBackToMainMenu");

        gridLayout_3->addWidget(btnComeBackToMainMenu, 5, 1, 1, 1);

        stackedWidget->addWidget(pageChooseMap);
        pageLoading = new QWidget();
        pageLoading->setObjectName("pageLoading");
        gridLayout_4 = new QGridLayout(pageLoading);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_8, 4, 0, 1, 1);

        labLoading = new QLabel(pageLoading);
        labLoading->setObjectName("labLoading");
        labLoading->setMinimumSize(QSize(100, 100));
        labLoading->setMaximumSize(QSize(100, 100));
        labLoading->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labLoading, 1, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_7, 0, 0, 1, 1);

        label = new QLabel(pageLoading);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 30));
        label->setMaximumSize(QSize(100, 30));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 2, 0, 1, 1);

        btnComeBackToChooseMap = new QPushButton(pageLoading);
        btnComeBackToChooseMap->setObjectName("btnComeBackToChooseMap");

        gridLayout_4->addWidget(btnComeBackToChooseMap, 3, 0, 1, 1);

        stackedWidget->addWidget(pageLoading);
        pageGame = new QWidget();
        pageGame->setObjectName("pageGame");
        horizontalLayout = new QHBoxLayout(pageGame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widgetGame = new GameWidget(pageGame);
        widgetGame->setObjectName("widgetGame");

        horizontalLayout->addWidget(widgetGame);

        stackedWidget->addWidget(pageGame);
        pageGameOver = new QWidget();
        pageGameOver->setObjectName("pageGameOver");
        gridLayout_5 = new QGridLayout(pageGameOver);
        gridLayout_5->setObjectName("gridLayout_5");
        verticalSpacer_9 = new QSpacerItem(20, 161, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_9, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(179, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        labGameOver = new QLabel(pageGameOver);
        labGameOver->setObjectName("labGameOver");
        labGameOver->setMinimumSize(QSize(300, 100));
        labGameOver->setMaximumSize(QSize(300, 100));
        QFont font4;
        font4.setPointSize(40);
        font4.setBold(true);
        labGameOver->setFont(font4);
        labGameOver->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(labGameOver, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(179, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        btnGameOver = new QPushButton(pageGameOver);
        btnGameOver->setObjectName("btnGameOver");

        gridLayout_5->addWidget(btnGameOver, 2, 1, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 161, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_10, 3, 1, 1, 1);

        stackedWidget->addWidget(pageGameOver);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labTitle->setText(QCoreApplication::translate("Widget", "TANK WAR", nullptr));
        btnSingleMode->setText(QCoreApplication::translate("Widget", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\244\232\344\272\272\350\201\224\346\234\272", nullptr));
        btnStartGame->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        labChooseMap->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\345\234\260\345\233\276", nullptr));
        btnComeBackToMainMenu->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        labLoading->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "\345\212\240\350\275\275\344\270\255", nullptr));
        btnComeBackToChooseMap->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        labGameOver->setText(QCoreApplication::translate("Widget", "DEFEAT", nullptr));
        btnGameOver->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
