QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    w1.cpp \
    w2.cpp \
    widget.cpp

HEADERS += \
    w1.h \
    w2.h \
    widget.h

FORMS += \
    w1.ui \
    w2.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    music.qrc \
    pic.qrc

DISTFILES += \
    2656f2a44e84dca.jpg \
    778682.png \
    TankFighter.pro.user \
    e429b5ec4d16213857ab1ebdc78055db.png
