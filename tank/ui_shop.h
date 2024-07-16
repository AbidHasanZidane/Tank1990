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
    QLabel *label;               // 显示背景图片的标签
    QLabel *label_2;             // 显示背景图片的标签
    QLabel *label_3;             // 显示商店标题的标签
    QPushButton *pushButton;     // 按钮，用于返回主界面
    QLabel *label_4;             // 显示血量图标的标签
    QLabel *label_5;             // 显示速度图标的标签
    QLabel *label_6;             // 显示火力图标的标签
    QPushButton *pushButton_2;   // 血量升级按钮
    QPushButton *pushButton_3;   // 速度升级按钮
    QPushButton *pushButton_4;   // 火力升级按钮
    QLabel *label_7;             // 血量升级价格标签
    QLabel *label_8;             // 速度升级价格标签
    QLabel *label_9;             // 火力升级价格标签
    QLabel *label_10;            // 表示血量已达到最大值的标签
    QLabel *label_11;            // 表示速度已达到最大值的标签
    QLabel *label_12;            // 表示火力已达到最大值的标签
    QLabel *label_13;            // 显示金币图标的标签
    QLabel *label_14;            // 显示当前金币数量的标签
    QLabel *label_15;            // 血量升级价格标签
    QLabel *label_16;            // 显示金币图标的标签
    QLabel *label_17;            // 速度升级价格标签
    QLabel *label_18;            // 显示金币图标的标签
    QLabel *label_19;            // 火力升级价格标签
    QLabel *label_20;            // 显示金币图标的标签

    void setupUi(QWidget *shop)
    {
        if (shop->objectName().isEmpty())
            shop->setObjectName("shop");
        shop->resize(1280, 720);    // 设置窗口大小
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        shop->setWindowIcon(icon);  // 设置窗口图标
        label = new QLabel(shop);   // 创建背景图片标签
        label->setObjectName("label");
        label->setGeometry(QRect(280, 0, 720, 720));  // 设置背景图片的位置和大小
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/shelf.png")));  // 加载并设置背景图片
        label->setScaledContents(true);  // 根据标签大小自动缩放图片
        label_2 = new QLabel(shop);   // 创建背景图片标签
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 1280, 720));  // 设置背景图片的位置和大小
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/board.jpg")));  // 加载并设置背景图片
        label_3 = new QLabel(shop);   // 创建商店标题标签
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-90, 105, 509, 509));  // 设置商店标题的位置和大小
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/titleShop.png")));  // 加载并设置商店标题图片
        label_3->setScaledContents(true);  // 根据标签大小自动缩放图片
        pushButton = new QPushButton(shop);  // 创建返回按钮
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 30, 100, 50));  // 设置返回按钮的位置和大小
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);  // 设置按钮文本字体大小
        pushButton->setFocusPolicy(Qt::NoFocus);  // 设置按钮无焦点状态
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));  // 设置按钮背景色
        label_4 = new QLabel(shop);   // 创建血量图标标签
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(560, 20, 160, 160));  // 设置血量图标的位置和大小
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/HP.png")));  // 加载并设置血量图标图片
        label_4->setScaledContents(true);  // 根据标签大小自动缩放图片
        label_5 = new QLabel(shop);   // 创建速度图标标签
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(560, 220, 160, 160));  // 设置速度图标的位置和大小
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/speed.png")));  // 加载并设置速度图标图片
        label_5->setScaledContents(true);  // 根据标签大小自动缩放图片
        label_6 = new QLabel(shop);   // 创建火力图标标签
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(560, 420, 160, 160));  // 设置火力图标的位置和大小
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/fire.png")));  // 加载并设置火力图标图片
        label_6->setScaledContents(true);  // 根据标签大小自动缩放图片
        pushButton_2 = new QPushButton(shop);  // 创建血量升级按钮
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 20, 160, 160));  // 设置血量升级按钮的位置和大小
        pushButton_2->setStyleSheet(QString::fromUtf8("background:transparent;"));  // 设置按钮透明背景
        pushButton_2->setFlat(true);  // 设置按钮为扁平样式
        pushButton_3 = new QPushButton(shop);  // 创建速度升级按钮
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(560, 220, 160, 160));  // 设置速度升级按钮的位置和大小
        pushButton_3->setStyleSheet(QString::fromUtf8("background:transparent;"));  // 设置按钮透明背景
        pushButton_3->setFlat(true);  // 设置按钮为扁平样式
        pushButton_4 = new QPushButton(shop);  // 创建火力升级按钮
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(560, 420, 160, 160));  // 设置火力升级按钮的位置和大小
        pushButton_4->setStyleSheet(QString::fromUtf8("background:transparent;"));  // 设置按钮透明背景
        pushButton_4->setFlat(true);  // 设置按钮为扁平样式
        label_7 = new QLabel(shop);   // 创建血量升级价格标签
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(680, 150, 80, 30));  // 设置血量升级价格标签的位置和大小
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Minecraft")});  // 设置字体族
        font1.setPointSize(20);  // 设置字体大小
        font1.setBold(true);  // 设置字体加粗
        label_7->setFont(font1);  // 设置标签字体
        label_8 = new QLabel(shop);   // 创建速度升级价格标签
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(680, 350, 80, 30));  // 设置速度升级价格标签的位置和大小
        label_8->setFont(font1);  // 设置标签字体
        label_9 = new QLabel(shop);   // 创建火力升级价格标签
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(680, 550, 80, 30));  // 设置火力升级价格标签的位置和大小
        label_9->setFont(font1);  // 设置标签字体
        label_10 = new QLabel(shop);  // 创建血量已达到最大值标签
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(542, 90, 200, 30));  // 设置血量已达到最大值标签的位置和大小
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Minecraft")});  // 设置字体族
        font2.setPointSize(25);  // 设置字体大小
        font2.setBold(true);  // 设置字体加粗
        label_10->setFont(font2);  // 设置标签字体
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));  // 设置标签文本颜色
        label_10->setScaledContents(false);  // 取消根据标签大小自动缩放图片
        label_11 = new QLabel(shop);  // 创建速度已达到最大值标签
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(542, 290, 200, 30));  // 设置速度已达到最大值标签的位置和大小
        label_11->setFont(font2);  // 设置标签字体
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));  // 设置标签文本颜色
        label_12 = new QLabel(shop);  // 创建火力已达到最大值标签
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(542, 490, 200, 30));  // 设置火力已达到最大值标签的位置和大小
        label_12->setFont(font2);  // 设置标签字体
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));  // 设置标签文本颜色
        label_13 = new QLabel(shop);  // 创建金币图标标签
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(1000, 0, 100, 100));  // 设置金币图标的位置和大小
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));  // 加载并设置金币图标图片
        label_13->setScaledContents(true);  // 根据标签大小自动缩放图片
        label_14 = new QLabel(shop);  // 创建当前金币数量标签
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1090, 20, 180, 60));  // 设置当前金币数量标签的位置和大小
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Minecraft")});  // 设置字体族
        font3.setPointSize(30);  // 设置字体大小
        font3.setBold(true);  // 设置字体加粗
        label_14->setFont(font3);  // 设置标签字体
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 191, 0);"));  // 设置标签文本颜色
        label_15 = new QLabel(shop);  // 创建血量升级价格标签
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(780, 120, 90, 60));  // 设置血量升级价格标签的位置和大小
        label_15->setFont(font2);  // 设置标签字体
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 191, 0);"));  // 设置标签文本颜色
        label_16 = new QLabel(shop);  // 创建金币图标标签
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(870, 110, 70, 70));  // 设置金币图标的位置和大小
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));  // 加载并设置金币图标图片
        label_16->setScaledContents(true);  // 根据标签大小自动缩放图片
        label_17 = new QLabel(shop);  // 创建速度升级价格标签
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(780, 320, 121, 60));  // 设置速度升级价格标签的位置和大小
        label_17->setFont(font2);  // 设置标签字体
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 191, 0);"));  // 设置标签文本颜色
        label_18 = new QLabel(shop);  // 创建金币图标标签
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(870, 310, 70, 70));  // 设置金币图标的位置和大小
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));  // 加载并设置金币图标图片
        label_18->setScaledContents(true);  // 根据标签大小自动缩放图片
        label_19 = new QLabel(shop);  // 创建火力升级价格标签
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(780, 530, 121, 60));  // 设置火力升级价格标签的位置和大小
        label_19->setFont(font2);  // 设置标签字体
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 191, 0);"));  // 设置标签文本颜色
        label_20 = new QLabel(shop);  // 创建金币图标标签
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(870, 520, 70, 70));  // 设置金币图标的位置和大小
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));  // 加载并设置金币图标图片
        label_20->setScaledContents(true);  // 根据标签大小自动缩放图片

        label_2->raise();  // 将背景图片标签置于顶层
        label->raise();    // 将背景图片标签置于顶层
        label_3->raise();  // 将商店标题标签置于顶层
        pushButton->raise();  // 将返回按钮置于顶层
        label_4->raise();  // 将血量图标标签置于顶层
        label_5->raise();  // 将速度图标标签置于顶层
        label_6->raise();  // 将火力图标标签置于顶层
        label_7->raise();  // 将血量升级价格标签置于顶层
        label_8->raise();  // 将速度升级价格标签置于顶层
        label_9->raise();  // 将火力升级价格标签置于顶层
        label_10->raise(); // 将血量已达到最大值标签置于顶层
        label_11->raise(); // 将速度已达到最大值标签置于顶层
        label_12->raise(); // 将火力已达到最大值标签置于顶层
        pushButton_2->raise();  // 将血量升级按钮置于顶层
        pushButton_3->raise();  // 将速度升级按钮置于顶层
        pushButton_4->raise();  // 将火力升级按钮置于顶层
        label_13->raise();  // 将金币图标标签置于顶层
        label_14->raise();  // 将当前金币数量标签置于顶层
        label_15->raise();  // 将血量升级价格标签置于顶层
        label_16->raise();  // 将金币图标标签置于顶层
        label_17->raise();  // 将速度升级价格标签置于顶层
        label_18->raise();  // 将金币图标标签置于顶层
        label_19->raise();  // 将火力升级价格标签置于顶层
        label_20->raise();  // 将金币图标标签置于顶层

        retranslateUi(shop);  // 调用翻译界面函数

        QMetaObject::connectSlotsByName(shop);  // 根据对象名连接槽函数
    } // setupUi

    void retranslateUi(QWidget *shop)
    {
        shop->setWindowTitle(QCoreApplication::translate("shop", "\345\235\246\345\205\213\345\244\247\346\210\230 by TANK MAKERS", nullptr));  // 设置窗口标题
        label_2->setText(QString());  // 设置背景图片标签文本
        label_3->setText(QString());  // 设置商店标题标签文本
        pushButton->setText(QCoreApplication::translate("shop", "\350\277\224 \345\233\236", nullptr));  // 设置返回按钮文本
        label_4->setText(QString());  // 设置血量图标标签文本
        label_5->setText(QString());  // 设置速度图标标签文本
        label_6->setText(QString());  // 设置火力图标标签文本
        pushButton_2->setText(QString());  // 设置血量升级按钮文本
        pushButton_3->setText(QString());  // 设置速度升级按钮文本
        pushButton_4->setText(QString());  // 设置火力升级按钮文本
        label_7->setText(QString());  // 设置血量升级价格标签文本
        label_8->setText(QString());  // 设置速度升级价格标签文本
        label_9->setText(QString());  // 设置火力升级价格标签文本
        label_10->setText(QCoreApplication::translate("shop", "MAXED OUT", nullptr));  // 设置血量已达到最大值标签文本
        label_11->setText(QCoreApplication::translate("shop", "MAXED OUT", nullptr));  // 设置速度已达到最大值标签文本
        label_12->setText(QCoreApplication::translate("shop", "MAXED OUT", nullptr));  // 设置火力已达到最大值标签文本
        label_13->setText(QString());  // 设置金币图标标签文本
        label_14->setText(QString());  // 设置当前金币数量标签文本
        label_15->setText(QCoreApplication::translate("shop", "2000", nullptr));  // 设置血量升级价格标签文本
        label_16->setText(QString());  // 设置金币图标标签文本
        label_17->setText(QCoreApplication::translate("shop", "2000", nullptr));  // 设置速度升级价格标签文本
        label_18->setText(QString());  // 设置金币图标标签文本
        label_19->setText(QCoreApplication::translate("shop", "2000", nullptr));  // 设置火力升级价格标签文本
        label_20->setText(QString());  // 设置金币图标标签文本
    } // retranslateUi

};

namespace Ui {
    class shop: public Ui_shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
