/********************************************************************************
** Form generated from reading UI file 'pause.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSE_H
#define UI_PAUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pause
{
public:

    void setupUi(QWidget *pause)
    {
        if (pause->objectName().isEmpty())
            pause->setObjectName("pause");
        pause->resize(640, 540);

        retranslateUi(pause);

        QMetaObject::connectSlotsByName(pause);
    } // setupUi

    void retranslateUi(QWidget *pause)
    {
        pause->setWindowTitle(QCoreApplication::translate("pause", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pause: public Ui_pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
