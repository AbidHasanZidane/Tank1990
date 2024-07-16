/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QWidget *centralwidget;  // 中央部件
    QPushButton *pushButton;  // 返回主菜单按钮
    QPushButton *ReTty;  // 重新尝试按钮
    QMenuBar *menubar;  // 菜单栏
    QStatusBar *statusbar;  // 状态栏

    void setupUi(QMainWindow *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName("GameOver");  // 设置游戏结束窗口对象名称
        GameOver->resize(1440, 810);  // 设置窗口大小
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        GameOver->setWindowIcon(icon);  // 设置窗口图标
        centralwidget = new QWidget(GameOver);  // 创建中央部件
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);  // 创建返回主菜单按钮
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 520, 281, 131));  // 设置按钮位置和大小
        ReTty = new QPushButton(centralwidget);  // 创建重新尝试按钮
        ReTty->setObjectName("ReTty");
        ReTty->setGeometry(QRect(860, 520, 281, 131));  // 设置按钮位置和大小
        GameOver->setCentralWidget(centralwidget);  // 将中央部件设置为游戏结束窗口的中心部件
        menubar = new QMenuBar(GameOver);  // 创建菜单栏
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1440, 17));  // 设置菜单栏位置和大小
        GameOver->setMenuBar(menubar);  // 设置游戏结束窗口的菜单栏
        statusbar = new QStatusBar(GameOver);  // 创建状态栏
        statusbar->setObjectName("statusbar");
        GameOver->setStatusBar(statusbar);  // 设置游戏结束窗口的状态栏

        retranslateUi(GameOver);  // 更新界面文字内容

        QMetaObject::connectSlotsByName(GameOver);  // 自动连接对象信号到槽函数
    } // setupUi

    void retranslateUi(QMainWindow *GameOver)
    {
        // 界面翻译函数，设置窗口标题和按钮的文本内容
        GameOver->setWindowTitle(QCoreApplication::translate("GameOver", "游戏结束 by TANK MAKERS", nullptr));
        pushButton->setText(QCoreApplication::translate("GameOver", "返回主菜单", nullptr));
        ReTty->setText(QCoreApplication::translate("GameOver", "重新尝试", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
