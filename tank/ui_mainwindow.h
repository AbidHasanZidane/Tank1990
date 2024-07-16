/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;  // 中央部件
    QMenuBar *menuBar;  // 菜单栏
    QMenu *menu1280;  // 分辨率菜单
    QToolBar *mainToolBar;  // 主工具栏
    QStatusBar *statusBar;  // 状态栏

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");  // 设置主窗口对象名称
        MainWindow->resize(1440, 810);  // 设置窗口大小
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);  // 设置窗口图标
        centralWidget = new QWidget(MainWindow);  // 创建中央部件
        centralWidget->setObjectName("centralWidget");
        MainWindow->setCentralWidget(centralWidget);  // 将中央部件设置为主窗口的中心部件
        menuBar = new QMenuBar(MainWindow);  // 创建菜单栏
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1440, 17));  // 设置菜单栏位置和大小
        menu1280 = new QMenu(menuBar);  // 创建分辨率菜单
        menu1280->setObjectName("menu1280");
        MainWindow->setMenuBar(menuBar);  // 设置主窗口的菜单栏
        mainToolBar = new QToolBar(MainWindow);  // 创建主工具栏
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);  // 将主工具栏添加到主窗口的顶部工具栏区域
        statusBar = new QStatusBar(MainWindow);  // 创建状态栏
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);  // 设置主窗口的状态栏

        menuBar->addAction(menu1280->menuAction());  // 在菜单栏上添加分辨率菜单的动作

        retranslateUi(MainWindow);  // 更新界面文字内容

        QMetaObject::connectSlotsByName(MainWindow);  // 自动连接对象信号到槽函数
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        // 界面翻译函数，设置窗口标题和菜单项的文本内容
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "主窗口 by TANK MAKERS", nullptr));
        menu1280->setTitle(QCoreApplication::translate("MainWindow", "1280", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
