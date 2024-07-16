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
    QPushButton *pushButton_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *pause)
    {
        if (pause->objectName().isEmpty())
            pause->setObjectName("pause");
        pause->resize(640, 540);
        label = new QLabel(pause);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 20, 260, 60));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        font.setUnderline(false);
        font.setStrikeOut(false);
        label->setFont(font);
        pushButton = new QPushButton(pause);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 250, 260, 60));
        QFont font1;
        font1.setPointSize(15);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(pause);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 350, 260, 60));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(pause);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(190, 450, 260, 60));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(pause);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(190, 150, 260, 60));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(pause);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 640, 540));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Minecraft")});
        font2.setBold(true);
        label_2->setFont(font2);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/pause.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(pause);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 90, 50, 50));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(pause);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 100, 150, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Minecraft")});
        font3.setPointSize(20);
        font3.setBold(true);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 215, 0);"));
        label_2->raise();
        label->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton->raise();
        label_3->raise();
        label_4->raise();

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
        pushButton_4->setText(QCoreApplication::translate("pause", "\350\256\276 \347\275\256", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pause: public Ui_pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
