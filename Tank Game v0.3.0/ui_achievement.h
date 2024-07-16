/********************************************************************************
** Form generated from reading UI file 'achievement.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACHIEVEMENT_H
#define UI_ACHIEVEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_achievement
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *achievement)
    {
        if (achievement->objectName().isEmpty())
            achievement->setObjectName("achievement");
        achievement->resize(1280, 720);
        label = new QLabel(achievement);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/achievement.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(achievement);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-240, 10, 700, 700));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/ribbon.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(achievement);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-55, 150, 350, 350));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/titleAchivement.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(achievement);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 1280, 720));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 235, 225);"));
        label_5 = new QLabel(achievement);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(300, 170, 400, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(20);
        font.setBold(false);
        label_5->setFont(font);
        pushButton = new QPushButton(achievement);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 30, 100, 50));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(achievement);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 270, 400, 60));
        label_6->setFont(font);
        label_7 = new QLabel(achievement);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(300, 370, 400, 60));
        label_7->setFont(font);
        label_8 = new QLabel(achievement);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(300, 470, 400, 60));
        label_8->setFont(font);
        label_4->raise();
        label_2->raise();
        label->raise();
        label_3->raise();
        label_5->raise();
        pushButton->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();

        retranslateUi(achievement);

        QMetaObject::connectSlotsByName(achievement);
    } // setupUi

    void retranslateUi(QWidget *achievement)
    {
        achievement->setWindowTitle(QCoreApplication::translate("achievement", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton->setText(QCoreApplication::translate("achievement", "\350\277\224 \345\233\236", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class achievement: public Ui_achievement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHIEVEMENT_H
