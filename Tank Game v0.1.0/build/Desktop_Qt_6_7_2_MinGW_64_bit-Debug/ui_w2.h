/********************************************************************************
** Form generated from reading UI file 'w2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W2_H
#define UI_W2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w2
{
public:
    QPushButton *pushButton;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *horizontalSlider_2;

    void setupUi(QWidget *w2)
    {
        if (w2->objectName().isEmpty())
            w2->setObjectName("w2");
        w2->resize(1280, 720);
        w2->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/config.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        w2->setWindowIcon(icon);
        w2->setAutoFillBackground(false);
        pushButton = new QPushButton(w2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 30, 70, 35));
        horizontalSlider = new QSlider(w2);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(450, 100, 512, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(w2);
        label->setObjectName("label");
        label->setGeometry(QRect(412, 87, 41, 41));
        label->setScaledContents(true);
        label_2 = new QLabel(w2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 97, 111, 20));
        QFont font;
        font.setPointSize(15);
        label_2->setFont(font);
        label_2->setScaledContents(false);
        label_3 = new QLabel(w2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 150, 111, 20));
        label_3->setFont(font);
        label_3->setScaledContents(false);
        label_4 = new QLabel(w2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(412, 140, 41, 41));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/sound.png")));
        label_4->setScaledContents(true);
        horizontalSlider_2 = new QSlider(w2);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(450, 153, 512, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        retranslateUi(w2);

        QMetaObject::connectSlotsByName(w2);
    } // setupUi

    void retranslateUi(QWidget *w2)
    {
        w2->setWindowTitle(QCoreApplication::translate("w2", "\350\256\276\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("w2", "\350\277\224\345\233\236", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("w2", "\351\237\263 \344\271\220 \351\237\263 \351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("w2", "\351\237\263 \346\225\210 \351\237\263 \351\207\217", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class w2: public Ui_w2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W2_H
