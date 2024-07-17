/********************************************************************************
** Form generated from reading UI file 'w1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W1_H
#define UI_W1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w1
{
public:
    QLabel *label;

    void setupUi(QWidget *w1)
    {
        if (w1->objectName().isEmpty())
            w1->setObjectName("w1");
        w1->resize(1280, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        w1->setWindowIcon(icon);
        w1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label = new QLabel(w1);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        label->setScaledContents(true);

        retranslateUi(w1);

        QMetaObject::connectSlotsByName(w1);
    } // setupUi

    void retranslateUi(QWidget *w1)
    {
        w1->setWindowTitle(QCoreApplication::translate("w1", "\345\235\246\345\205\213\345\244\247\346\210\230 by TANK MAKERS", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class w1: public Ui_w1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W1_H
