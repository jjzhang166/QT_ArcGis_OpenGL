#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T20:45:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArcGisWP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form3d.cpp \
    formexcel.cpp \
    opengl/glwidget.cpp

HEADERS  += mainwindow.h \
    form3d.h \
    formexcel.h \
    opengl/glwidhet.h

FORMS    += mainwindow.ui \
    form3d.ui \
    formexcel.ui

QT += core gui opengl
