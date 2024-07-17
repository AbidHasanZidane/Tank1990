/********************************************************************************
** Form generated from reading UI file 'mainwindow3.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW3_H
#define UI_MAINWINDOW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow3
{
public:
    QPushButton *BACK;

    void setupUi(QWidget *MainWindow3)
    {
        if (MainWindow3->objectName().isEmpty())
            MainWindow3->setObjectName("MainWindow3");
        MainWindow3->resize(1440, 810);
        MainWindow3->setStyleSheet(QString::fromUtf8("background-image: url(:/90Tank/player_tank/OKOCIN.png);"));
        BACK = new QPushButton(MainWindow3);
        BACK->setObjectName("BACK");
        BACK->setGeometry(QRect(510, 570, 351, 171));
        BACK->setStyleSheet(QString::fromUtf8("image: url(:/90Tank/player_tank/MENU.png);"));

        retranslateUi(MainWindow3);

        QMetaObject::connectSlotsByName(MainWindow3);
    } // setupUi

    void retranslateUi(QWidget *MainWindow3)
    {
        MainWindow3->setWindowTitle(QCoreApplication::translate("MainWindow3", "Form", nullptr));
        BACK->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow3: public Ui_MainWindow3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW3_H
