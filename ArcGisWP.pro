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
    opengl/glwidget.cpp \
    frmmain.cpp \
    frmmessagebox.cpp \
    initform.cpp \
    mainform.cpp \
    paint2ddialog.cpp \
    paint2dform.cpp \
    paint3dform.cpp \
    helper/iconhelper.cpp

HEADERS  += \
    opengl/glwidhet.h \
    frmmain.h \
    frmmessagebox.h \
    initform.h \
    mainform.h \
    paint2ddialog.h \
    paint2dform.h \
    paint3dform.h \
    helper/iconhelper.h \
    helper/myhelper.h

FORMS    += \
    frmmain.ui \
    frmmessagebox.ui \
    initform.ui \
    mainform.ui \
    paint2ddialog.ui \
    paint2dform.ui \
    paint3dform.ui

QT += core gui opengl
CONFIG += qaxcontainer
RESOURCES += \
    rc.qrc
