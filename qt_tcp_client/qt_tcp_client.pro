QT += core network
QT -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = qt_tcp_client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    qt_redis_client.h

