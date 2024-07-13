/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QWidget *centralwidget;
    QPushButton *BACK;
    QPushButton *NEXT;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName("MainWindow2");
        MainWindow2->resize(1440, 810);
        MainWindow2->setStyleSheet(QString::fromUtf8("background-image: url(:/90Tank/player_tank/OKOCIN.png);"));
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName("centralwidget");
        BACK = new QPushButton(centralwidget);
        BACK->setObjectName("BACK");
        BACK->setGeometry(QRect(200, 440, 261, 141));
        BACK->setStyleSheet(QString::fromUtf8("image: url(:/90Tank/player_tank/MENU.png);"));
        NEXT = new QPushButton(centralwidget);
        NEXT->setObjectName("NEXT");
        NEXT->setGeometry(QRect(950, 440, 321, 171));
        NEXT->setStyleSheet(QString::fromUtf8("image: url(:/90Tank/player_tank/NEIS.png);"));
        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1440, 17));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName("statusbar");
        MainWindow2->setStatusBar(statusbar);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        BACK->setText(QString());
        NEXT->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
