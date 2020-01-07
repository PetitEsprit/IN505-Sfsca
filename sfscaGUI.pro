#-------------------------------------------------
#
# Project created by QtCreator 2019-12-27T14:04:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sfscaGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    src/GUI/mainwindow.cpp \
    src/GUI/motoritem.cpp \
    src/GUI/tankitem.cpp \
    src/GUI/valveitem.cpp \
    src/parts/Motor.cpp \
    src/parts/Part.cpp \
    src/parts/System.cpp \
    src/parts/Tank.cpp \
    src/parts/Valve.cpp \
    src/GUI/sfscascene.cpp \
    src/security/Login.cpp \
    src/security/sha512.cpp \
    src/utils/Grade.cpp

HEADERS += \
    inc/mainwindow.h \
    inc/tankitem.h \
    inc/valveitem.h \
    inc/motoritem.h \
    inc/Valve.hpp \
    inc/Tank.hpp \
    inc/System.hpp \
    inc/Part.hpp \
    inc/Motor.hpp \
    inc/sfscascene.h \
    inc/Grade.hpp \
    inc/Login.hpp \
    inc/sha512.hpp

INCLUDEPATH += $$PWD/inc

FORMS += \
        mainwindow.ui
