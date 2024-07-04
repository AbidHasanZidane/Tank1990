/********************************************************************************
** Form generated from reading UI file 'w1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W1_H
#define UI_W1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w1
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *w1)
    {
        if (w1->objectName().isEmpty())
            w1->setObjectName("w1");
        w1->resize(1280, 720);
        textEdit = new QTextEdit(w1);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(540, 310, 200, 100));

        retranslateUi(w1);

        QMetaObject::connectSlotsByName(w1);
    } // setupUi

    void retranslateUi(QWidget *w1)
    {
        w1->setWindowTitle(QCoreApplication::translate("w1", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("w1", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">//To do</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class w1: public Ui_w1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W1_H
