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
    QLabel *label;  // 标题标签
    QPushButton *pushButton;  // 继续按钮
    QPushButton *pushButton_2;  // 重新开始按钮
    QPushButton *pushButton_3;  // 返回主菜单按钮
    QPushButton *pushButton_4;  // 退出游戏按钮
    QLabel *label_2;  // 背景图片标签
    QLabel *label_3;  // 金币图标标签
    QLabel *label_4;  // 金币数量标签

    void setupUi(QWidget *pause)
    {
        if (pause->objectName().isEmpty())
            pause->setObjectName("pause");  // 设置窗口对象名称
        pause->resize(640, 540);  // 设置窗口大小
        label = new QLabel(pause);  // 创建标题标签
        label->setObjectName("label");
        label->setGeometry(QRect(190, 20, 260, 60));  // 设置标题标签位置和大小
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(40);  // 设置标题字体大小
        font.setBold(true);  // 设置标题字体加粗
        label->setFont(font);
        pushButton = new QPushButton(pause);  // 创建继续按钮
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 250, 260, 60));  // 设置继续按钮位置和大小
        QFont font1;
        font1.setPointSize(15);  // 设置按钮字体大小
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));  // 设置按钮样式为白色背景
        pushButton_2 = new QPushButton(pause);  // 创建重新开始按钮
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 350, 260, 60));  // 设置重新开始按钮位置和大小
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));  // 设置按钮样式为白色背景
        pushButton_3 = new QPushButton(pause);  // 创建返回主菜单按钮
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(190, 450, 260, 60));  // 设置返回主菜单按钮位置和大小
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));  // 设置按钮样式为白色背景
        pushButton_4 = new QPushButton(pause);  // 创建退出游戏按钮
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(190, 150, 260, 60));  // 设置退出游戏按钮位置和大小
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));  // 设置按钮样式为白色背景
        label_2 = new QLabel(pause);  // 创建背景图片标签
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 640, 540));  // 设置背景图片标签位置和大小
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Minecraft")});  // 设置字体族为 Minecraft
        font2.setBold(true);  // 设置字体加粗
        label_2->setFont(font2);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/pause.png")));  // 设置背景图片
        label_2->setScaledContents(true);  // 设置背景图片自适应窗口大小显示
        label_3 = new QLabel(pause);  // 创建金币图标标签
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 90, 50, 50));  // 设置金币图标标签位置和大小
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/coin.png")));  // 设置金币图标
        label_3->setScaledContents(true);  // 设置金币图标自适应大小显示
        label_4 = new QLabel(pause);  // 创建金币数量标签
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 100, 150, 30));  // 设置金币数量标签位置和大小
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Minecraft")});  // 设置字体族为 Minecraft
        font3.setPointSize(20);  // 设置字体大小
        font3.setBold(true);  // 设置字体加粗
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 215, 0);"));  // 设置金币数量标签文字颜色为金黄色
        label_2->raise();  // 将背景图片标签置于最上层
        label->raise();  // 将标题标签置于最上层
        pushButton_2->raise();  // 将重新开始按钮置于最上层
        pushButton_3->raise();  // 将返回主菜单按钮置于最上层
        pushButton_4->raise();  // 将退出游戏按钮置于最上层
        pushButton->raise();  // 将继续按钮置于最上层
        label_3->raise();  // 将金币图标标签置于最上层
        label_4->raise();  // 将金币数量标签置于最上层

        retranslateUi(pause);  // 更新界面文字内容

        QMetaObject::connectSlotsByName(pause);  // 自动连接对象信号到槽函数
    } // setupUi

    void retranslateUi(QWidget *pause)
    {
        // 界面翻译函数，设置窗口标题和按钮的文本内容
        pause->setWindowTitle(QCoreApplication::translate("pause", "表单", nullptr));
        label->setText(QCoreApplication::translate("pause", "\346\270\270 \346\210\217 \346\232\202 \345\201\234", nullptr));  // 设置标题文字
        pushButton->setText(QCoreApplication::translate("pause", "\345\233\236 \345\210\260 \346\270\270 \346\210\217", nullptr));  // 设置继续按钮文字
        pushButton_2->setText(QCoreApplication::translate("pause", "\345\233\236 \345\210\260 \344\270\273 \350\217\234 \345\215\225", nullptr));  // 设置重新开始按钮文字
        pushButton_3->setText(QCoreApplication::translate("pause", "\351\200\200 \345\207\272 \346\270\270 \346\210\217", nullptr));  // 设置返回主菜单按钮文字
        pushButton_4->setText(QCoreApplication::translate("pause", "\350\256\276 \347\275\256", nullptr));  // 设置退出游戏按钮文字
        label_2->setText(QString());  // 清空背景图片标签文字内容
        label_3->setText(QString());  // 清空金币图标标签文字内容
        label_4->setText(QString());  // 清空金币数量标签文字内容
    } // retranslateUi

};

namespace Ui {
    class pause: public Ui_pause {};  // 命名空间定义界面类
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
