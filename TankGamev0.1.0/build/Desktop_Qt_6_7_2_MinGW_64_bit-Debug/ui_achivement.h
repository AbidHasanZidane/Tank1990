/********************************************************************************
** Form generated from reading UI file 'achivement.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACHIVEMENT_H
#define UI_ACHIVEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_achivement
{
public:

    void setupUi(QWidget *achivement)
    {
        if (achivement->objectName().isEmpty())
            achivement->setObjectName("achivement");
        achivement->resize(1280, 720);

        retranslateUi(achivement);

        QMetaObject::connectSlotsByName(achivement);
    } // setupUi

    void retranslateUi(QWidget *achivement)
    {
        achivement->setWindowTitle(QCoreApplication::translate("achivement", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class achivement: public Ui_achivement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHIVEMENT_H
