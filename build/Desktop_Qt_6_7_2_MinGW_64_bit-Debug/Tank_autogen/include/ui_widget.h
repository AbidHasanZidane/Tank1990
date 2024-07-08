/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QToolButton *toolButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1280, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/778682.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Widget->setWindowIcon(icon);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(520, 560, 240, 60));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(520, 630, 240, 60));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFrameShape(QFrame::NoFrame);
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/e429b5ec4d16213857ab1ebdc78055db.png")));
        label->setScaledContents(true);
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(1200, 650, 60, 51));
        toolButton->setMouseTracking(false);
        toolButton->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/2656f2a44e84dca.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setCheckable(false);
        toolButton->setAutoExclusive(false);
        toolButton->setPopupMode(QToolButton::InstantPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton->setArrowType(Qt::NoArrow);
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        toolButton->raise();

        retranslateUi(Widget);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\235\246\345\205\213\345\244\247\346\210\230 v0.0.1 test", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        label->setText(QString());
        toolButton->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
