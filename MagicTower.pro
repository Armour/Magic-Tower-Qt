#-------------------------------------------------
#
# Project created by QtCreator 2014-11-25T17:28:15
#
#-------------------------------------------------

QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MagicTower
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cheat.cpp \
    database.cpp \
    myview.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    cheat.h \
    database.h \
    equip.h \
    key.h \
    monster.h \
    myview.h \
    player.h \
    role.h
