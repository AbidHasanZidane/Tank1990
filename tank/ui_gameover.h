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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName("GameOver");
        GameOver->resize(1440, 810);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        GameOver->setWindowIcon(icon);
        GameOver->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/resources/WJKADSKL.png);"));
        centralwidget = new QWidget(GameOver);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 520, 331, 151));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/pic/resources/MENU.png);"));
        ReTty = new QPushButton(centralwidget);
        ReTty->setObjectName("ReTty");
        ReTty->setGeometry(QRect(860, 520, 311, 151));
        ReTty->setStyleSheet(QString::fromUtf8("image: url(:/pic/resources/RESTART.png);"));
        GameOver->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(GameOver);
        statusbar->setObjectName("statusbar");
        GameOver->setStatusBar(statusbar);

        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QMainWindow *GameOver)
    {
        GameOver->setWindowTitle(QCoreApplication::translate("GameOver", "\345\235\246\345\205\213\345\244\247\346\210\230 by TANK MAKERS", nullptr));
        pushButton->setText(QString());
        ReTty->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
