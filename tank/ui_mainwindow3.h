/********************************************************************************
** Form generated from reading UI file 'mainwindow3.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW3_H
#define UI_MAINWINDOW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow3
{
public:
    QPushButton *BACK;  // 返回按钮

    void setupUi(QWidget *MainWindow3)
    {
        if (MainWindow3->objectName().isEmpty())
            MainWindow3->setObjectName("MainWindow3");  // 设置主窗口对象名称
        MainWindow3->resize(1440, 810);  // 设置窗口大小
        BACK = new QPushButton(MainWindow3);  // 创建返回按钮
        BACK->setObjectName("BACK");
        BACK->setGeometry(QRect(670, 590, 361, 131));  // 设置按钮位置和大小

        retranslateUi(MainWindow3);  // 更新界面文字内容

        QMetaObject::connectSlotsByName(MainWindow3);  // 自动连接对象信号到槽函数
    } // setupUi

    void retranslateUi(QWidget *MainWindow3)
    {
        // 界面翻译函数，设置窗口标题和按钮的文本内容
        MainWindow3->setWindowTitle(QCoreApplication::translate("MainWindow3", "表单", nullptr));
        BACK->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow3: public Ui_MainWindow3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW3_H
