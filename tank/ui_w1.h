/********************************************************************************
** Form generated from reading UI file 'w1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W1_H
#define UI_W1_H

#include <QtCore/QVariant>  // 包含Qt的核心模块中处理变体数据的头文件
#include <QtGui/QIcon>      // 包含Qt的图形用户界面模块中处理图标的头文件
#include <QtWidgets/QApplication>  // 包含Qt的窗口部件模块中处理应用程序的头文件
#include <QtWidgets/QLabel>       // 包含Qt的窗口部件模块中处理标签的头文件
#include <QtWidgets/QWidget>      // 包含Qt的窗口部件模块中处理窗口的头文件

QT_BEGIN_NAMESPACE  // Qt命名空间开始

class Ui_w1  // 定义名为Ui_w1的用户界面类
{
public:
    QLabel *label;  // 声明一个指向QLabel类型的指针变量label

    void setupUi(QWidget *w1)  // 设置UI界面的函数，接收一个QWidget类型的指针参数w1
    {
        if (w1->objectName().isEmpty())  // 如果窗口对象名为空
            w1->setObjectName("w1");     // 设置窗口对象名为"w1"
        w1->resize(1280, 720);           // 设置窗口大小为1280x720像素
        QIcon icon;                      // 创建一个QIcon对象
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        // 添加一个图标文件到QIcon对象中，图标文件路径从资源文件中加载
        w1->setWindowIcon(icon);         // 设置窗口的图标为上面创建的图标
        w1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));  // 设置窗口背景颜色为黑色
        label = new QLabel(w1);          // 在窗口w1上创建一个QLabel对象label
        label->setObjectName("label");   // 设置label对象名为"label"
        label->setGeometry(QRect(0, 0, 1280, 720));  // 设置label的位置和大小与窗口相同
        label->setScaledContents(true);  // 根据label大小自动缩放内容

        retranslateUi(w1);  // 调用retranslateUi函数，设置界面的翻译

        QMetaObject::connectSlotsByName(w1);  // 根据对象名连接槽函数
    } // setupUi

    void retranslateUi(QWidget *w1)  // 界面翻译函数，接收一个QWidget类型的指针参数w1
    {
        w1->setWindowTitle(QCoreApplication::translate("w1", "\345\235\246\345\205\213\345\244\247\346\210\230 by TANK MAKERS", nullptr));
        // 设置窗口标题，翻译为中文字符，用于显示游戏名称
        label->setText(QString());  // 设置label文本为空字符串
    } // retranslateUi

};

namespace Ui {
    class w1: public Ui_w1 {};  // 命名空间Ui中定义一个名为w1的类，继承自Ui_w1类
} // namespace Ui

QT_END_NAMESPACE  // Qt命名空间结束

#endif // UI_W1_H  // 宏定义结束标志
