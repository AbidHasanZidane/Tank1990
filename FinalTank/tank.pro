#-------------------------------------------------
#
# Project created by QtCreator 2024-07-03T08:44:40
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tank
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


SOURCES += \
    Heart.cpp \
    achievement.cpp \
        main.cpp \
        mainwindow.cpp \
    mainwindow3.cpp \
    mytank.cpp \
    bullet.cpp \
    enemy.cpp \
    building.cpp \
    enemybullet.cpp \
    mainwindow2.cpp \
    gameover.cpp \
    boss.cpp \
    bossbullet.cpp \
    pause.cpp \
    settings.cpp \
    shop.cpp \
    w1.cpp \
    w2.cpp \
    widget.cpp

HEADERS += \
    Heart.h \
    achievement.h \
        mainwindow.h \
    mainwindow3.h \
    mytank.h \
    bullet.h \
    enemy.h \
    building.h \
    enemybullet.h \
    mainwindow2.h \
    gameover.h \
    boss.h \
    bossbullet.h \
    pause.h \
    settings.h \
    shop.h \
    w1.h \
    w2.h \
    widget.h

FORMS += \
    achievement.ui \
        mainwindow.ui \
    mainwindow2.ui \
    gameover.ui \
    mainwindow3.ui \
    pause.ui \
    shop.ui \
    w1.ui \
    w2.ui \
    widget.ui

RESOURCES += \
    music.qrc \
    pic.qrc \
    tank.qrc \
    tank.qrc \
    tank.qrc

DISTFILES +=
