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
    QPushButton *pushButton_2;
    QLabel *label;
    QToolButton *toolButton;
    QLabel *label_2;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1280, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Widget->setWindowIcon(icon);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(520, 630, 240, 60));
        QFont font;
        font.setPointSize(15);
        pushButton_2->setFont(font);
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFrameShape(QFrame::NoFrame);
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/resources/background.png")));
        label->setScaledContents(true);
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(1187, 630, 60, 60));
        QFont font1;
        font1.setPointSize(10);
        toolButton->setFont(font1);
        toolButton->setMouseTracking(false);
        toolButton->setFocusPolicy(Qt::NoFocus);
        toolButton->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/resources/config.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setCheckable(false);
        toolButton->setAutoExclusive(false);
        toolButton->setPopupMode(QToolButton::InstantPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton->setArrowType(Qt::NoArrow);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(475, 545, 400, 40));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213")});
        font2.setPointSize(25);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        toolButton_2 = new QToolButton(Widget);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setGeometry(QRect(33, 630, 60, 60));
        toolButton_2->setFont(font1);
        toolButton_2->setMouseTracking(false);
        toolButton_2->setFocusPolicy(Qt::NoFocus);
        toolButton_2->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/resources/achivements.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(40, 40));
        toolButton_2->setCheckable(false);
        toolButton_2->setAutoExclusive(false);
        toolButton_2->setPopupMode(QToolButton::InstantPopup);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_2->setArrowType(Qt::NoArrow);
        toolButton_3 = new QToolButton(Widget);
        toolButton_3->setObjectName("toolButton_3");
        toolButton_3->setGeometry(QRect(110, 630, 60, 60));
        toolButton_3->setFont(font1);
        toolButton_3->setMouseTracking(false);
        toolButton_3->setFocusPolicy(Qt::NoFocus);
        toolButton_3->setAutoFillBackground(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pic/resources/shop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(40, 40));
        toolButton_3->setCheckable(false);
        toolButton_3->setAutoExclusive(false);
        toolButton_3->setPopupMode(QToolButton::InstantPopup);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_3->setArrowType(Qt::NoArrow);
        label->raise();
        toolButton->raise();
        pushButton_2->raise();
        label_2->raise();
        toolButton_2->raise();
        toolButton_3->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\235\246\345\205\213\345\244\247\346\210\230 by TANK MAKERS", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\351\200\200 \345\207\272", nullptr));
        label->setText(QString());
        toolButton->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\214\211 \344\273\273 \346\204\217 \351\224\256 \345\274\200 \345\247\213 \346\270\270 \346\210\217", nullptr));
        toolButton_2->setText(QCoreApplication::translate("Widget", "\346\210\220\345\260\261", nullptr));
        toolButton_3->setText(QCoreApplication::translate("Widget", "\345\225\206\345\272\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
