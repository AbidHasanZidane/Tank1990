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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pause
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *pause)
    {
        if (pause->objectName().isEmpty())
            pause->setObjectName("pause");
        pause->resize(640, 540);
        pause->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 209, 209);"));
        label = new QLabel(pause);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 40, 260, 60));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        pushButton = new QPushButton(pause);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 150, 260, 60));
        QFont font1;
        font1.setPointSize(15);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(pause);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 250, 260, 60));
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(pause);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(190, 350, 260, 60));
        pushButton_3->setFont(font1);

        retranslateUi(pause);

        QMetaObject::connectSlotsByName(pause);
    } // setupUi

    void retranslateUi(QWidget *pause)
    {
        pause->setWindowTitle(QCoreApplication::translate("pause", "Form", nullptr));
        label->setText(QCoreApplication::translate("pause", "\346\270\270 \346\210\217 \346\232\202 \345\201\234", nullptr));
        pushButton->setText(QCoreApplication::translate("pause", "\345\233\236 \345\210\260 \346\270\270 \346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pause", "\345\233\236 \345\210\260 \344\270\273 \350\217\234 \345\215\225", nullptr));
        pushButton_3->setText(QCoreApplication::translate("pause", "\351\200\200 \345\207\272 \346\270\270 \346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pause: public Ui_pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
