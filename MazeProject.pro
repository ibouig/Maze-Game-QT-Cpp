#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T17:54:46
#
#-------------------------------------------------

QT       += core gui \
             multimedia
INCLUDEPATH += .

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MazeProject
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        menu.cpp \
    maze.cpp \
    prim.cpp \
    sidewinder.cpp \
    growing_tree.cpp \
    game.cpp

HEADERS  += \
         menu.h \
    maze.h \
    prim.h \
    sidewinder.h \
    growing_tree.h \
    game.h

FORMS    +=

RESOURCES += \
    resources.qrc
