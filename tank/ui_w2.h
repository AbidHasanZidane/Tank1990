/********************************************************************************
** Form generated from reading UI file 'w2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W2_H
#define UI_W2_H

#include <QtCore/QVariant>         // 包含Qt的核心模块中处理变体数据的头文件
#include <QtGui/QIcon>             // 包含Qt的图形用户界面模块中处理图标的头文件
#include <QtWidgets/QApplication>  // 包含Qt的窗口部件模块中处理应用程序的头文件
#include <QtWidgets/QComboBox>     // 包含Qt的窗口部件模块中处理组合框的头文件
#include <QtWidgets/QLabel>        // 包含Qt的窗口部件模块中处理标签的头文件
#include <QtWidgets/QPushButton>   // 包含Qt的窗口部件模块中处理按钮的头文件
#include <QtWidgets/QSlider>       // 包含Qt的窗口部件模块中处理滑动条的头文件
#include <QtWidgets/QWidget>       // 包含Qt的窗口部件模块中处理窗口的头文件

QT_BEGIN_NAMESPACE  // Qt命名空间开始

class Ui_w2  // 定义名为Ui_w2的用户界面类
{
public:
    QPushButton *pushButton;        // 声明一个指向QPushButton类型的指针变量pushButton
    QSlider *horizontalSlider;      // 声明一个指向QSlider类型的指针变量horizontalSlider
    QLabel *label;                  // 声明一个指向QLabel类型的指针变量label
    QLabel *label_2;                // 声明一个指向QLabel类型的指针变量label_2
    QLabel *label_3;                // 声明一个指向QLabel类型的指针变量label_3
    QLabel *label_4;                // 声明一个指向QLabel类型的指针变量label_4
    QSlider *horizontalSlider_2;    // 声明一个指向QSlider类型的指针变量horizontalSlider_2
    QComboBox *comboBox;            // 声明一个指向QComboBox类型的指针变量comboBox
    QPushButton *pushButton_2;      // 声明一个指向QPushButton类型的指针变量pushButton_2
    QLabel *label_5;                // 声明一个指向QLabel类型的指针变量label_5

    void setupUi(QWidget *w2)  // 设置UI界面的函数，接收一个QWidget类型的指针参数w2
    {
        if (w2->objectName().isEmpty())  // 如果窗口对象名为空
            w2->setObjectName("w2");     // 设置窗口对象名为"w2"
        w2->resize(1280, 720);           // 设置窗口大小为1280x720像素
        w2->setSizeIncrement(QSize(0, 0));  // 设置窗口的尺寸增量为0
        QIcon icon;                      // 创建一个QIcon对象
        icon.addFile(QString::fromUtf8(":/pic/resources/config.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        // 添加一个图标文件到QIcon对象中，图标文件路径从资源文件中加载
        w2->setWindowIcon(icon);         // 设置窗口的图标为上面创建的图标
        w2->setAutoFillBackground(false);  // 禁用窗口的自动填充背景
        pushButton = new QPushButton(w2);  // 在窗口w2上创建一个QPushButton对象pushButton
        pushButton->setObjectName("pushButton");  // 设置pushButton对象名为"pushButton"
        pushButton->setGeometry(QRect(40, 30, 100, 50));  // 设置pushButton的位置和大小
        QFont font;                      // 创建一个QFont对象
        font.setPointSize(12);           // 设置字体大小为12点
        pushButton->setFont(font);       // 设置pushButton的字体为上面创建的字体
        pushButton->setFocusPolicy(Qt::NoFocus);  // 设置pushButton的焦点策略为无焦点
        horizontalSlider = new QSlider(w2);  // 在窗口w2上创建一个QSlider对象horizontalSlider
        horizontalSlider->setObjectName("horizontalSlider");  // 设置horizontalSlider对象名为"horizontalSlider"
        horizontalSlider->setGeometry(QRect(450, 103, 500, 16));  // 设置horizontalSlider的位置和大小
        horizontalSlider->setOrientation(Qt::Horizontal);  // 设置horizontalSlider的方向为水平方向
        label = new QLabel(w2);          // 在窗口w2上创建一个QLabel对象label
        label->setObjectName("label");   // 设置label对象名为"label"
        label->setGeometry(QRect(410, 90, 41, 41));  // 设置label的位置和大小
        label->setScaledContents(true);  // 根据label大小自动缩放内容
        label_2 = new QLabel(w2);        // 在窗口w2上创建一个QLabel对象label_2
        label_2->setObjectName("label_2");  // 设置label_2对象名为"label_2"
        label_2->setGeometry(QRect(310, 100, 110, 20));  // 设置label_2的位置和大小
        QFont font1;                     // 创建一个QFont对象font1
        font1.setPointSize(15);          // 设置字体大小为15点
        label_2->setFont(font1);         // 设置label_2的字体为上面创建的字体
        label_2->setScaledContents(false);  // 禁止label_2自动缩放内容
        label_3 = new QLabel(w2);        // 在窗口w2上创建一个QLabel对象label_3
        label_3->setObjectName("label_3");  // 设置label_3对象名为"label_3"
        label_3->setGeometry(QRect(310, 170, 110, 20));  // 设置label_3的位置和大小
        label_3->setFont(font1);         // 设置label_3的字体为上面创建的字体
        label_3->setScaledContents(false);  // 禁止label_3自动缩放内容
        label_4 = new QLabel(w2);        // 在窗口w2上创建一个QLabel对象label_4
        label_4->setObjectName("label_4");  // 设置label_4对象名为"label_4"
        label_4->setGeometry(QRect(410, 160, 41, 41));  // 设置label_4的位置和大小
        label_4->setScaledContents(true);  // 根据label_4大小自动缩放内容
        horizontalSlider_2 = new QSlider(w2);  // 在窗口w2上创建一个QSlider对象horizontalSlider_2
        horizontalSlider_2->setObjectName("horizontalSlider_2");  // 设置horizontalSlider_2对象名为"horizontalSlider_2"
        horizontalSlider_2->setGeometry(QRect(450, 173, 500, 16));  // 设置horizontalSlider_2的位置和大小
        horizontalSlider_2->setOrientation(Qt::Horizontal);  // 设置horizontalSlider_2的方向为水平方向
        comboBox = new QComboBox(w2);    // 在窗口w2上创建一个QComboBox对象comboBox
        comboBox->setObjectName("comboBox");  // 设置comboBox对象名为"comboBox"
        comboBox->setGeometry(QRect(450, 230, 500, 40));  // 设置comboBox的位置和大小
        comboBox->setFont(font1);       // 设置comboBox的字体为上面创建的字体
        comboBox->setFocusPolicy(Qt::NoFocus);  // 设置comboBox的焦点策略为无焦点
        pushButton_2 = new QPushButton(w2);  // 在窗口w2上创建一个QPushButton对象pushButton_2
        pushButton_2->setObjectName("pushButton_2");  // 设置pushButton_2对象名为"pushButton_2"
        pushButton_2->setGeometry(QRect(310, 360, 640, 50));  // 设置pushButton_2的位置和大小
        pushButton_2->setFont(font1);   // 设置pushButton_2的字体为上面创建的字体
        pushButton_2->setFocusPolicy(Qt::NoFocus);  // 设置pushButton_2的焦点策略为无焦点
        label_5 = new QLabel(w2);        // 在窗口w2上创建一个QLabel对象label_5
        label_5->setObjectName("label_5");  // 设置label_5对象名为"label_5"
        label_5->setGeometry(QRect(310, 240, 130, 20));  // 设置label_5的位置和大小
        label_5->setFont(font1);         // 设置label_5的字体为上面创建的字体
        label_5->setScaledContents(false);  // 禁止label_5自动缩放内容

        retranslateUi(w2);  // 调用retranslateUi函数，设置界面的翻译

        QMetaObject::connectSlotsByName(w2);  // 根据对象名连接槽函数
    } // setupUi

    void retranslateUi(QWidget *w2)  // 界面翻译函数，接收一个QWidget类型的指针参数w2
    {
        w2->setWindowTitle(QCoreApplication::translate("w2", "\350\256\276\347\275\256", nullptr));
        // 设置窗口标题，翻译为中文字符，用于显示游戏名称
        pushButton->setText(QCoreApplication::translate("w2", "\350\277\224 \345\233\236", nullptr));
        // 设置pushButton按钮文本，翻译为中文字符，用于显示特定功能的按钮文本
        label->setText(QString());  // 设置label文本为空字符串
        label_2->setText(QCoreApplication::translate("w2", "\351\237\263 \344\271\220 \351\237\263 \351\207\217", nullptr));
        // 设置label_2文本，翻译为中文字符，用于显示特定说明文本
        label_3->setText(QCoreApplication::translate("w2", "\351\237\263 \346\225\210 \351\237\263 \351\207\217", nullptr));
        // 设置label_3文本，翻译为中文字符，用于显示特定说明文本
        label_4->setText(QString());  // 设置label_4文本为空字符串
        pushButton_2->setText(QCoreApplication::translate("w2", "\346\201\242 \345\244\215 \351\273\230 \350\256\244 \350\256\276 \347\275\256", nullptr));
        // 设置pushButton_2按钮文本，翻译为中文字符，用于显示特定功能的按钮文本
        label_5->setText(QCoreApplication::translate("w2", "\346\270\270 \346\210\217 \345\210\206 \350\276\250 \347\216\207", nullptr));
        // 设置label_5文本，翻译为中文字符，用于显示特定说明文本
    } // retranslateUi

};

namespace Ui {
    class w2: public Ui_w2 {};  // 命名空间Ui中定义一个名为w2的类，继承自Ui_w2类
} // namespace Ui

QT_END_NAMESPACE  // Qt命名空间结束

#endif // UI_W2_H  // 宏定义结束标志
