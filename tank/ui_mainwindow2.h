/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QWidget *centralwidget;  // 中央部件
    QPushButton *BACK;  // 返回按钮
    QPushButton *NEXT;  // 下一步按钮
    QStatusBar *statusbar;  // 状态栏

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName("MainWindow2");  // 设置主窗口对象名称
        MainWindow2->resize(1440, 810);  // 设置窗口大小
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow2->setWindowIcon(icon);  // 设置窗口图标
        centralwidget = new QWidget(MainWindow2);  // 创建中央部件
        centralwidget->setObjectName("centralwidget");
        BACK = new QPushButton(centralwidget);  // 创建返回按钮
        BACK->setObjectName("BACK");
        BACK->setGeometry(QRect(200, 440, 251, 131));  // 设置按钮位置和大小
        NEXT = new QPushButton(centralwidget);  // 创建下一步按钮
        NEXT->setObjectName("NEXT");
        NEXT->setGeometry(QRect(1000, 440, 251, 131));  // 设置按钮位置和大小
        MainWindow2->setCentralWidget(centralwidget);  // 将中央部件设置为主窗口的中心部件
        statusbar = new QStatusBar(MainWindow2);  // 创建状态栏
        statusbar->setObjectName("statusbar");
        MainWindow2->setStatusBar(statusbar);  // 设置主窗口的状态栏

        retranslateUi(MainWindow2);  // 更新界面文字内容

        QMetaObject::connectSlotsByName(MainWindow2);  // 自动连接对象信号到槽函数
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        // 界面翻译函数，设置窗口标题和按钮的文本内容
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "主窗口2 by TANK MAKERS", nullptr));
        BACK->setText(QCoreApplication::translate("MainWindow2", "返回主菜单", nullptr));
        NEXT->setText(QCoreApplication::translate("MainWindow2", "下一步", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
