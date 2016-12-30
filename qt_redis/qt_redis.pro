QT += core
QT -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = qt_redis
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    example-qt.cpp \
    ../../../redis/hiredis/async.c \
    ../../../redis/hiredis/dict.c \
    ../../../redis/hiredis/hiredis.c \
    ../../../redis/hiredis/net.c \
    ../../../redis/hiredis/read.c \
    ../../../redis/hiredis/sds.c \
    qt_redis_sync_connection.cpp

HEADERS += \
    example-qt.h \
    ../../../redis/hiredis/async.h \
    ../../../redis/hiredis/dict.h \
    ../../../redis/hiredis/fmacros.h \
    ../../../redis/hiredis/hiredis.h \
    ../../../redis/hiredis/net.h \
    ../../../redis/hiredis/read.h \
    ../../../redis/hiredis/sds.h \
    ../../../redis/hiredis/sdsalloc.h \
    ../../../redis/hiredis/win32.h \
    ../../../redis/hiredis/adapters/qt.h \
    qt_redis_sync_connection.h

INCLUDEPATH += ../../../redis/hiredis \
	../../../redis/hiredis/adapters
