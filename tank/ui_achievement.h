/********************************************************************************
** Form generated from reading UI file 'achievement.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACHIEVEMENT_H
#define UI_ACHIEVEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_achievement
{
public:
    QLabel *label;  // 成就界面背景图片标签
    QLabel *label_2;  // 成就界面顶部装饰图标签
    QLabel *label_3;  // 成就标题图标标签
    QLabel *label_4;  // 背景颜色填充标签
    QLabel *label_5;  // 成就描述文本标签
    QPushButton *pushButton;  // 返回按钮
    QLabel *label_6;  // 成就1描述标签
    QLabel *label_7;  // 成就2描述标签
    QLabel *label_8;  // 成就3描述标签

    void setupUi(QWidget *achievement)
    {
        if (achievement->objectName().isEmpty())
            achievement->setObjectName("achievement");  // 设置成就界面对象名称
        achievement->resize(1280, 720);  // 设置成就界面大小
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        achievement->setWindowIcon(icon);  // 设置窗口图标

        label = new QLabel(achievement);  // 创建并设置背景图片标签
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/achievement.png")));
        label->setScaledContents(true);

        label_2 = new QLabel(achievement);  // 创建并设置顶部装饰图标签
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-240, 10, 700, 700));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/ribbon.png")));
        label_2->setScaledContents(true);

        label_3 = new QLabel(achievement);  // 创建并设置成就标题图标签
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-55, 150, 350, 350));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/titleAchivement.png")));
        label_3->setScaledContents(true);

        label_4 = new QLabel(achievement);  // 创建并设置背景颜色填充标签
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 1280, 720));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 235, 225);"));

        label_5 = new QLabel(achievement);  // 创建并设置成就描述文本标签
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(300, 170, 400, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(20);
        font.setBold(false);
        label_5->setFont(font);

        pushButton = new QPushButton(achievement);  // 创建并设置返回按钮
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 30, 100, 50));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        label_6 = new QLabel(achievement);  // 创建并设置成就1描述标签
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 270, 400, 60));
        label_6->setFont(font);

        label_7 = new QLabel(achievement);  // 创建并设置成就2描述标签
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(300, 370, 400, 60));
        label_7->setFont(font);

        label_8 = new QLabel(achievement);  // 创建并设置成就3描述标签
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(300, 470, 400, 60));
        label_8->setFont(font);

        // 设置控件层级关系
        label_4->raise();
        label_2->raise();
        label->raise();
        label_3->raise();
        label_5->raise();
        pushButton->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();

        retranslateUi(achievement);  // 更新界面文字内容

        QMetaObject::connectSlotsByName(achievement);  // 自动连接对象信号到槽函数
    } // setupUi

    void retranslateUi(QWidget *achievement)
    {
        // 界面翻译函数，设置窗口标题和各标签的文本内容
        achievement->setWindowTitle(QCoreApplication::translate("achievement", "成就展示 by TANK MAKERS", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton->setText(QCoreApplication::translate("achievement", "返回", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class achievement: public Ui_achievement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHIEVEMENT_H
