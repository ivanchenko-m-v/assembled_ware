#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T12:34:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dialog_search_ware
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ../assembled_ware_ui/source/data_objects

SOURCES += main.cpp\
    line_edit_ware_search.cpp \
    completer_ware_search.cpp \
    data_model_ware_search.cpp \
    dialog_ware_search.cpp

HEADERS  += \
    line_edit_ware_search.h \
    completer_ware_search.h \
    data_model_ware_search.h \
    dialog_ware_search.h \
    ../assembled_ware_ui/source/data_objects/data_collection.h \
    ../assembled_ware_ui/source/data_objects/data_ware.h
