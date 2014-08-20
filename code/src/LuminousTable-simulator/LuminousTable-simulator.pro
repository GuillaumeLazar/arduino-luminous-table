#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T10:35:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LuminousTable-simulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qdotmatrix.cpp \
    TableBehaviorRandomDot.cpp \
    AbstractTableBehavior.cpp \
    TableBehaviorSnake.cpp \
    TableBehaviorUnicolor.cpp \
    TableBehaviorDarkSky.cpp \
    TableBehaviorPixelart.cpp \
    TableBehaviorVUmeter.cpp \
    TableBehaviorVUmeterB.cpp \
    TableBehaviorRandomDotSound.cpp

HEADERS  += mainwindow.h \
    qdotmatrix.h \
    FakeHardware.h \
    TableBehaviorRandomDot.h \
    AbstractTableBehavior.h \
    TableBehaviorSnake.h \
    TableBehaviorUnicolor.h \
    TableBehaviorDarkSky.h \
    TableBehaviorPixelart.h \
    TableBehaviorVUmeter.h \
    TableBehaviorVUmeterB.h \
    TableBehaviorRandomDotSound.h

#FORMS    +=

DEFINES += MODE_SIMULATOR

OTHER_FILES +=
