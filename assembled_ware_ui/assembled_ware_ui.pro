
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = assembled_ware_ui
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += source/app \
				source/gui \
				source/logic

SOURCES +=\
    source/app/application.cpp \
    source/app/application_log.cpp \
    source/app/application_params.cpp \
    source/app/main.cpp \
    source/logic/business_logic.cpp \
    source/gui/main_window.cpp \
    source/gui/widget_central.cpp

HEADERS  += \
    source/app/application.h \
    source/app/application_log.h \
    source/app/application_params.h \
    source/logic/business_logic.h \
    source/gui/main_window.h \
    source/gui/widget_central.h


MOC_DIR = ./xmoc

OBJECTS_DIR = ./xobj

RCC_DIR = ./xrcc

RESOURCES += \
    source/res/app.qrc

TRANSLATIONS += source/ts/strings_ru.ts
