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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName("MainWindow2");
        MainWindow2->resize(1440, 810);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow2->setWindowIcon(icon);
        MainWindow2->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/resources/OKOCIN.png);"));
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName("centralwidget");
        BACK = new QPushButton(centralwidget);
        BACK->setObjectName("BACK");
        BACK->setGeometry(QRect(200, 440, 311, 141));
        BACK->setStyleSheet(QString::fromUtf8("image: url(:/pic/resources/MENU.png);"));
        NEXT = new QPushButton(centralwidget);
        NEXT->setObjectName("NEXT");
        NEXT->setGeometry(QRect(1000, 440, 371, 151));
        NEXT->setStyleSheet(QString::fromUtf8("image: url(:/pic/resources/NEIS.png);"));
        MainWindow2->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName("statusbar");
        MainWindow2->setStatusBar(statusbar);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "\345\235\246\345\205\213\345\244\247\346\210\230 by TANK MAKERS", nullptr));
        BACK->setText(QString());
        NEXT->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
