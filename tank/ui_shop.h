/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shop
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;

    void setupUi(QWidget *shop)
    {
        if (shop->objectName().isEmpty())
            shop->setObjectName("shop");
        shop->resize(1280, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        shop->setWindowIcon(icon);
        label = new QLabel(shop);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 0, 720, 720));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/shelf.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(shop);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 1280, 720));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/board.jpg")));
        label_3 = new QLabel(shop);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-90, 105, 509, 509));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/titleShop.png")));
        label_3->setScaledContents(true);
        pushButton = new QPushButton(shop);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 30, 100, 50));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(shop);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(560, 20, 160, 160));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/HP.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(shop);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(560, 220, 160, 160));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/speed.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(shop);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(560, 420, 160, 160));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/fire.png")));
        label_6->setScaledContents(true);
        pushButton_2 = new QPushButton(shop);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 20, 160, 160));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(shop);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(560, 220, 160, 160));
        pushButton_3->setStyleSheet(QString::fromUtf8("background:transparent;"));
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(shop);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(560, 420, 160, 160));
        pushButton_4->setStyleSheet(QString::fromUtf8("background:transparent;"));
        pushButton_4->setFlat(true);
        label_7 = new QLabel(shop);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(680, 150, 80, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Minecraft")});
        font1.setPointSize(20);
        font1.setBold(true);
        label_7->setFont(font1);
        label_8 = new QLabel(shop);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(680, 350, 80, 30));
        label_8->setFont(font1);
        label_9 = new QLabel(shop);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(680, 550, 80, 30));
        label_9->setFont(font1);
        label_10 = new QLabel(shop);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(542, 90, 200, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Minecraft")});
        font2.setPointSize(25);
        font2.setBold(true);
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        label_10->setScaledContents(false);
        label_11 = new QLabel(shop);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(542, 290, 200, 30));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        label_12 = new QLabel(shop);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(542, 490, 200, 30));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        label_13 = new QLabel(shop);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(1000, 0, 100, 100));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));
        label_13->setScaledContents(true);
        label_14 = new QLabel(shop);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1090, 20, 180, 60));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Minecraft")});
        font3.setPointSize(30);
        font3.setBold(true);
        label_14->setFont(font3);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 191, 0);"));
        label_15 = new QLabel(shop);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(780, 120, 90, 60));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 191, 0);"));
        label_16 = new QLabel(shop);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(870, 110, 70, 70));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));
        label_16->setScaledContents(true);
        label_17 = new QLabel(shop);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(780, 320, 121, 60));
        label_17->setFont(font2);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 191, 0);"));
        label_18 = new QLabel(shop);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(870, 310, 70, 70));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));
        label_18->setScaledContents(true);
        label_19 = new QLabel(shop);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(780, 530, 121, 60));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 191, 0);"));
        label_20 = new QLabel(shop);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(870, 520, 70, 70));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));
        label_20->setScaledContents(true);
        label_2->raise();
        label->raise();
        label_3->raise();
        pushButton->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        label_13->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();
        label_20->raise();

        retranslateUi(shop);

        QMetaObject::connectSlotsByName(shop);
    } // setupUi

    void retranslateUi(QWidget *shop)
    {
        shop->setWindowTitle(QCoreApplication::translate("shop", "\345\235\246\345\205\213\345\244\247\346\210\230 by TANK MAKERS", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("shop", "\350\277\224 \345\233\236", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QCoreApplication::translate("shop", "MAXED OUT", nullptr));
        label_11->setText(QCoreApplication::translate("shop", "MAXED OUT", nullptr));
        label_12->setText(QCoreApplication::translate("shop", "MAXED OUT", nullptr));
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QCoreApplication::translate("shop", "2000", nullptr));
        label_16->setText(QString());
        label_17->setText(QCoreApplication::translate("shop", "2000", nullptr));
        label_18->setText(QString());
        label_19->setText(QCoreApplication::translate("shop", "2000", nullptr));
        label_20->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class shop: public Ui_shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
