/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName("MainScene");
        MainScene->resize(733, 597);
        centralWidget = new QWidget(MainScene);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 290, 101, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bernard MT Condensed")});
        font.setPointSize(16);
        font.setBold(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color::rgb(255, 255, 255)"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 420, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bernard MT Condensed")});
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 330, 271, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 370, 231, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 460, 271, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(80, 500, 231, 41));
        label_6->setFont(font1);
        MainScene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainScene);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 733, 26));
        MainScene->setMenuBar(menuBar);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QCoreApplication::translate("MainScene", "MainScene", nullptr));
        label->setText(QCoreApplication::translate("MainScene", "\347\216\251\345\256\2661\357\274\232   ", nullptr));
        label_2->setText(QCoreApplication::translate("MainScene", "\347\216\251\345\256\2662\357\274\232 ", nullptr));
        label_3->setText(QCoreApplication::translate("MainScene", "W S A D  \344\270\212\344\270\213\345\267\246\345\217\263\347\247\273\345\212\250", nullptr));
        label_4->setText(QCoreApplication::translate("MainScene", "J \345\260\204\345\207\273 K \344\275\277\347\224\250\351\201\223\345\205\267", nullptr));
        label_5->setText(QCoreApplication::translate("MainScene", "\342\206\221\342\206\223\342\206\220\342\206\222\344\270\212\344\270\213\345\267\246\345\217\263\347\247\273\345\212\250", nullptr));
        label_6->setText(QCoreApplication::translate("MainScene", "1 \345\260\204\345\207\273 2 \344\275\277\347\224\250\351\201\223\345\205\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
