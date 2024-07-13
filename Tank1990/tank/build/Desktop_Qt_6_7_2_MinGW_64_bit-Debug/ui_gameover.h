/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *ReTty;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName("GameOver");
        GameOver->resize(1440, 810);
        GameOver->setStyleSheet(QString::fromUtf8("background-image: url(:/90Tank/player_tank/WJKADSKL.png);"));
        centralwidget = new QWidget(GameOver);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 520, 281, 131));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/90Tank/player_tank/MENU.png);"));
        ReTty = new QPushButton(centralwidget);
        ReTty->setObjectName("ReTty");
        ReTty->setGeometry(QRect(840, 520, 301, 151));
        ReTty->setStyleSheet(QString::fromUtf8("image: url(:/90Tank/player_tank/RESTART(1).png);"));
        GameOver->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameOver);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1440, 17));
        GameOver->setMenuBar(menubar);
        statusbar = new QStatusBar(GameOver);
        statusbar->setObjectName("statusbar");
        GameOver->setStatusBar(statusbar);

        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QMainWindow *GameOver)
    {
        GameOver->setWindowTitle(QCoreApplication::translate("GameOver", "MainWindow", nullptr));
        pushButton->setText(QString());
        ReTty->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
