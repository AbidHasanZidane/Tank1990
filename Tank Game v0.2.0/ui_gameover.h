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
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName("GameOver");
        GameOver->resize(1440, 810);
        centralwidget = new QWidget(GameOver);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 520, 281, 131));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(860, 520, 281, 131));
        GameOver->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameOver);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1440, 26));
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
        pushButton->setText(QCoreApplication::translate("GameOver", "\350\277\224\345\233\236\350\217\234\345\215\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GameOver", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
