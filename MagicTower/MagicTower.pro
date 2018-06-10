#-------------------------------------------------
#
# Project created by QtCreator 2014-11-25T17:28:15
#
#-------------------------------------------------

QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MagicTower

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
    mainwindow.cpp \
    cheat.cpp \
    database.cpp \
    player.cpp \
    view.cpp

HEADERS += mainwindow.h \
    cheat.h \
    database.h \
    player.h \
    monster.h \
    role.h \
    tools.h \
    keys.h \
    view.h

RESOURCES += \
    application.qrc
