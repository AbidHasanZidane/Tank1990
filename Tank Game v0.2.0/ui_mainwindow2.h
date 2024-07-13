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
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName("centralwidget");
        BACK = new QPushButton(centralwidget);
        BACK->setObjectName("BACK");
        BACK->setGeometry(QRect(200, 440, 251, 131));
        NEXT = new QPushButton(centralwidget);
        NEXT->setObjectName("NEXT");
        NEXT->setGeometry(QRect(1000, 440, 251, 131));
        MainWindow2->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName("statusbar");
        MainWindow2->setStatusBar(statusbar);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        BACK->setText(QCoreApplication::translate("MainWindow2", "\350\277\224\345\233\236\350\217\234\345\215\225", nullptr));
        NEXT->setText(QCoreApplication::translate("MainWindow2", "\344\270\213\344\270\200\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
