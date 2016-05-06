#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T13:46:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = regexptest
TEMPLATE = app


SOURCES += main.cpp\
        regexptest.cpp \
    ../sid/sid.cpp

HEADERS  += regexptest.h \
    ../sid/sid.h \
    ../sid/sid_global.h

FORMS    += regexptest.ui

DISTFILES += \
    samples.re
