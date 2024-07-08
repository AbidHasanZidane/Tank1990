#-------------------------------------------------
#
# Project created by QtCreator 2022-03-24T21:02:55
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tank
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += resources_big
SOURCES += \
        main.cpp \
        mainscene.cpp \
    mypushbutton.cpp \
    playscene.cpp \
    choosemodelscene.cpp \
    playscene2.cpp \
    tank_s.cpp \
    bullet_s.cpp

HEADERS += \
        mainscene.h \
    mypushbutton.h \
    playscene.h \
    choosemodelscene.h \
    playscene2.h \
    tank_s.h \
    bullet_s.h


FORMS += \
        mainscene.ui

RESOURCES += \
    res.qrc \
    res2.qrc \
    res3.qrc \
    res4.qrc \
    res5.qrc

DISTFILES += \
    res5/icon_bomb.png \
    res5/playagain.png
