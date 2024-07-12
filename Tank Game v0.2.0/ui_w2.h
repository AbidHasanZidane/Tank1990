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
#include <QtWidgets/QComboBox>
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
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QLabel *label_5;

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
        pushButton->setGeometry(QRect(40, 30, 100, 50));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setFocusPolicy(Qt::NoFocus);
        horizontalSlider = new QSlider(w2);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(450, 103, 500, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(w2);
        label->setObjectName("label");
        label->setGeometry(QRect(410, 87, 41, 41));
        label->setScaledContents(true);
        label_2 = new QLabel(w2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 100, 110, 20));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_2->setScaledContents(false);
        label_3 = new QLabel(w2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 170, 110, 20));
        label_3->setFont(font1);
        label_3->setScaledContents(false);
        label_4 = new QLabel(w2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(410, 157, 41, 41));
        label_4->setScaledContents(true);
        horizontalSlider_2 = new QSlider(w2);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(450, 173, 500, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        comboBox = new QComboBox(w2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(450, 230, 500, 40));
        comboBox->setFont(font1);
        comboBox->setFocusPolicy(Qt::NoFocus);
        pushButton_2 = new QPushButton(w2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 360, 651, 50));
        pushButton_2->setFont(font1);
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        label_5 = new QLabel(w2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 240, 130, 20));
        label_5->setFont(font1);
        label_5->setScaledContents(false);

        retranslateUi(w2);

        QMetaObject::connectSlotsByName(w2);
    } // setupUi

    void retranslateUi(QWidget *w2)
    {
        w2->setWindowTitle(QCoreApplication::translate("w2", "\350\256\276\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("w2", "\350\277\224 \345\233\236", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("w2", "\351\237\263 \344\271\220 \351\237\263 \351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("w2", "\351\237\263 \346\225\210 \351\237\263 \351\207\217", nullptr));
        label_4->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("w2", "\346\201\242 \345\244\215 \351\273\230 \350\256\244 \350\256\276 \347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("w2", "\346\270\270 \346\210\217 \345\210\206 \350\276\250 \347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class w2: public Ui_w2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W2_H
