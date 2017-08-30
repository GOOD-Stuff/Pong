#-------------------------------------------------
#
# Project created by QtCreator 2017-08-18T12:45:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pong
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    network.cpp \
    drawer.cpp \
    gamefield.cpp

HEADERS  += mainwindow.h \
    player.h \
    network.h \
    drawer.h \
    gamefield.h

FORMS    += mainwindow.ui
