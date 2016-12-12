QT += core
QT -= gui

CONFIG += c++11

TARGET = ConvertText
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Writers/rtftextwriter.cpp \
    Writers/textwriter.cpp \
    Writers/bbcodetextwriter.cpp

HEADERS += \
    Writers/textwriter.h \
    Writers/rtftextwriter.h \
    Writers/bbcodetextwriter.h
