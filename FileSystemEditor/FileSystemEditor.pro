#-------------------------------------------------
#
# Project created by QtCreator 2018-06-11T23:09:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileSystemEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    root.cpp

HEADERS  += mainwindow.h \
    image.h \
    root.h \
    file.h

FORMS    += mainwindow.ui

DISTFILES += \
    hd0.img
