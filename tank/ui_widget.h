/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>         // 包含Qt的核心模块中处理变体数据的头文件
#include <QtGui/QIcon>             // 包含Qt的图形用户界面模块中处理图标的头文件
#include <QtWidgets/QApplication>  // 包含Qt的窗口部件模块中处理应用程序的头文件
#include <QtWidgets/QLabel>        // 包含Qt的窗口部件模块中处理标签的头文件
#include <QtWidgets/QPushButton>   // 包含Qt的窗口部件模块中处理按钮的头文件
#include <QtWidgets/QToolButton>   // 包含Qt的窗口部件模块中处理工具按钮的头文件
#include <QtWidgets/QWidget>       // 包含Qt的窗口部件模块中处理窗口的头文件

QT_BEGIN_NAMESPACE  // Qt命名空间开始

class Ui_Widget
{
public:
    QPushButton *pushButton_2;      // 声明一个指向QPushButton类型的指针变量pushButton_2
    QLabel *label;                  // 声明一个指向QLabel类型的指针变量label
    QToolButton *toolButton;        // 声明一个指向QToolButton类型的指针变量toolButton
    QLabel *label_2;                // 声明一个指向QLabel类型的指针变量label_2
    QToolButton *toolButton_2;      // 声明一个指向QToolButton类型的指针变量toolButton_2
    QToolButton *toolButton_3;      // 声明一个指向QToolButton类型的指针变量toolButton_3

    void setupUi(QWidget *Widget)   // 设置UI界面的函数，接收一个QWidget类型的指针参数Widget
    {
        if (Widget->objectName().isEmpty())  // 如果窗口对象名为空
            Widget->setObjectName("Widget");  // 设置窗口对象名为"Widget"
        Widget->resize(1280, 720);           // 设置窗口大小为1280x720像素
        QIcon icon;                          // 创建一个QIcon对象
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        // 添加一个图标文件到QIcon对象中，图标文件路径从资源文件中加载
        Widget->setWindowIcon(icon);         // 设置窗口的图标为上面创建的图标
        pushButton_2 = new QPushButton(Widget);  // 在窗口Widget上创建一个QPushButton对象pushButton_2
        pushButton_2->setObjectName("pushButton_2");  // 设置pushButton_2对象名为"pushButton_2"
        pushButton_2->setGeometry(QRect(520, 630, 240, 60));  // 设置pushButton_2的位置和大小
        QFont font;                          // 创建一个QFont对象
        font.setPointSize(15);               // 设置字体大小为15点
        pushButton_2->setFont(font);         // 设置pushButton_2的字体为上面创建的字体
        pushButton_2->setFocusPolicy(Qt::NoFocus);  // 设置pushButton_2的焦点策略为无焦点
        label = new QLabel(Widget);          // 在窗口Widget上创建一个QLabel对象label
        label->setObjectName("label");       // 设置label对象名为"label"
        label->setGeometry(QRect(0, 0, 1280, 720));  // 设置label的位置和大小
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);  // 创建一个QSizePolicy对象
        sizePolicy.setHorizontalStretch(0);  // 设置水平拉伸因子为0
        sizePolicy.setVerticalStretch(0);    // 设置垂直拉伸因子为0
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());  // 设置是否根据宽度自动调整高度
        label->setSizePolicy(sizePolicy);    // 设置label的大小策略为上面创建的大小策略
        label->setFrameShape(QFrame::NoFrame);  // 设置label的边框形状为无边框
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/background.png")));  // 设置label的图片内容，从资源文件加载
        label->setScaledContents(true);      // 根据label大小自动缩放内容
        toolButton = new QToolButton(Widget);  // 在窗口Widget上创建一个QToolButton对象toolButton
        toolButton->setObjectName("toolButton");  // 设置toolButton对象名为"toolButton"
        toolButton->setGeometry(QRect(1187, 630, 60, 60));  // 设置toolButton的位置和大小
        QFont font1;                         // 创建一个QFont对象
        font1.setPointSize(10);              // 设置字体大小为10点
        toolButton->setFont(font1);          // 设置toolButton的字体为上面创建的字体
        toolButton->setMouseTracking(false);  // 禁止toolButton的鼠标跟踪
        toolButton->setFocusPolicy(Qt::NoFocus);  // 设置toolButton的焦点策略为无焦点
        toolButton->setAutoFillBackground(false);  // 禁用toolButton的自动填充背景
        QIcon icon1;                         // 创建一个QIcon对象
        icon1.addFile(QString::fromUtf8(":/pic/resources/config.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        // 添加一个图标文件到QIcon对象中，图标文件路径从资源文件中加载
        toolButton->setIcon(icon1);         // 设置toolButton的图标为上面创建的图标
        toolButton->setIconSize(QSize(40, 40));  // 设置toolButton的图标大小
        toolButton->setCheckable(false);     // 设置toolButton不可选中
        toolButton->setAutoExclusive(false); // 设置toolButton不自动排他
        toolButton->setPopupMode(QToolButton::InstantPopup);  // 设置toolButton的弹出模式为即时弹出
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);  // 设置toolButton的按钮样式为图文下排
        toolButton->setArrowType(Qt::NoArrow);  // 设置toolButton的箭头类型为无箭头
        label_2 = new QLabel(Widget);        // 在窗口Widget上创建一个QLabel对象label_2
        label_2->setObjectName("label_2");   // 设置label_2对象名为"label_2"
        label_2->setGeometry(QRect(475, 545, 400, 40));  // 设置label_2的位置和大小
        QFont font2;                         // 创建一个QFont对象
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213")});  // 设置字体族
        font2.setPointSize(25);              // 设置字体大小为25点
        label_2->setFont(font2);             // 设置label_2的字体为上面创建的字体
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));  // 设置label_2的样式表为白色文本
        toolButton_2 = new QToolButton(Widget);  // 在窗口Widget上创建一个QToolButton对象toolButton_2
        toolButton_2->setObjectName("toolButton_2");  // 设置toolButton_2对象名为"toolButton_2"
        toolButton_2->setGeometry(QRect(33, 630, 60, 60));  // 设置toolButton_2的位置和大小
        toolButton_2->setFont(font1);       // 设置toolButton_2的字体为上面创建的字体
        toolButton_2->setMouseTracking(false);  // 禁止toolButton_2的鼠标跟踪
        toolButton_2->setFocusPolicy(Qt::NoFocus);  // 设置toolButton_2的焦点策略为无焦点
        toolButton_2->setAutoFillBackground(false);  // 禁用toolButton_2的自动填充背景
        QIcon icon2;                         // 创建一个QIcon对象
        icon2.addFile(QString::fromUtf8(":/pic/resources/achivements.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        // 添加一个图标文件到QIcon对象中，图标文件路径从资源文件中加载
        toolButton_2->setIcon(icon2);       // 设置toolButton_2的图标为上面创建的图标
        toolButton_2->setIconSize(QSize(40, 40));  // 设置toolButton_2的图标大小
        toolButton_2->setCheckable(false);  // 设置toolButton_2不可选中
        toolButton_2->setAutoExclusive(false);  // 设置toolButton_2不自动排他
        toolButton_2->setPopupMode(QToolButton::InstantPopup);  // 设置toolButton_2的弹出模式为即时弹出
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);  // 设置toolButton_2的按钮样式为图文下排
        toolButton_2->setArrowType(Qt::NoArrow);  // 设置toolButton_2的箭头类型为无箭头
        toolButton_3 = new QToolButton(Widget);  // 在窗口Widget上创建一个QToolButton对象toolButton_3
        toolButton_3->setObjectName("toolButton_3");  // 设置toolButton_3对象名为"toolButton_3"
        toolButton_3->setGeometry(QRect(110, 630, 60, 60));  // 设置toolButton_3的位置和大小
        toolButton_3->setFont(font1);       // 设置toolButton_3的字体为上面创建的字体
        toolButton_3->setMouseTracking(false);  // 禁止toolButton_3的鼠标跟踪
        toolButton_3->setFocusPolicy(Qt::NoFocus);  // 设置toolButton_3的焦点策略为无焦点
        toolButton_3->setAutoFillBackground(false);  // 禁用toolButton_3的自动填充背景
        QIcon icon3;                         // 创建一个QIcon对象
        icon3.addFile(QString::fromUtf8(":/pic/resources/shop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        // 添加一个图标文件到QIcon对象中，图标文件路径从资源文件中加载
        toolButton_3->setIcon(icon3);       // 设置toolButton_3的图标为上面创建的图标
        toolButton_3->setIconSize(QSize(40, 40));  // 设置toolButton_3的图标大小
        toolButton_3->setCheckable(false);  // 设置toolButton_3不可选中
        toolButton_3->setAutoExclusive(false);  // 设置toolButton_3不自动排他
        toolButton_3->setPopupMode(QToolButton::InstantPopup);  // 设置toolButton_3的弹出模式为即时弹出
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);  // 设置toolButton_3的按钮样式为图文下排
        toolButton_3->setArrowType(Qt::NoArrow);  // 设置toolButton_3的箭头类型为无箭头
        label->raise();                    // 将label置于最上层
        toolButton->raise();               // 将toolButton置于最上层
        pushButton_2->raise();             // 将pushButton_2置于最上层
        label_2->raise();                  // 将label_2置于最上层
        toolButton_2->raise();             // 将toolButton_2置于最上层
        toolButton_3->raise();             // 将toolButton_3置于最上层

        retranslateUi(Widget);             // 调用retranslateUi函数，设置界面的翻译

        QMetaObject::connectSlotsByName(Widget);  // 根据对象名连接槽函数
    } // setupUi

    void retranslateUi(QWidget *Widget)    // 界面翻译函数，接收一个QWidget类型的指针参数Widget
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\235\246\345\205\213\345\244\247\346\210\230 by TANK MAKERS", nullptr));
        // 设置窗口标题，翻译为中文字符，用于显示游戏名称
        pushButton_2->setText(QCoreApplication::translate("Widget", "\351\200\200 \345\207\272", nullptr));
        // 设置pushButton_2按钮文本，翻译为中文字符，用于显示特定功能的按钮文本
        label->setText(QString());         // 设置label文本为空字符串
        toolButton->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
        // 设置toolButton按钮文本，翻译为中文字符，用于显示特定功能的按钮文本
        label_2->setText(QCoreApplication::translate("Widget", "\346\214\211 \344\273\273 \346\204\217 \351\224\256 \345\274\200 \345\247\213 \346\270\270 \346\210\217", nullptr));
        // 设置label_2文本，翻译为中文字符，用于显示特定说明文本
        toolButton_2->setText(QCoreApplication::translate("Widget", "\346\210\220\345\260\261", nullptr));
        // 设置toolButton_2按钮文本，翻译为中文字符，用于显示特定功能的按钮文本
        toolButton_3->setText(QCoreApplication::translate("Widget", "\345\225\206\345\272\227", nullptr));
        // 设置toolButton_3按钮文本，翻译为中文字符，用于显示特定功能的按钮文本
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};  // 命名空间Ui中定义一个名为Widget的类，继承自Ui_Widget类
} // namespace Ui

QT_END_NAMESPACE  // Qt命名空间结束

#endif // UI_WIDGET_H  // 宏定义结束标志
