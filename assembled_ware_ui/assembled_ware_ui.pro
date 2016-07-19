
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = assembled_ware_ui
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += source/app \
				source/gui \
				source/logic \
				source/data_objects \
				source/data_models

SOURCES +=\
    source/app/application.cpp \
    source/app/application_log.cpp \
    source/app/application_params.cpp \
    source/app/main.cpp \
    source/logic/business_logic.cpp \
    source/gui/main_window.cpp \
    source/gui/widget_central.cpp \
    source/gui/panel_ware.cpp \
    source/gui/listview_ware.cpp \
    source/gui/panel_ware_detail.cpp \
    source/data_models/data_model_ware.cpp \
    source/gui/delegate_line_edit.cpp \
    source/gui/panel_ware_properties.cpp \
    source/gui/listview_ware_detail.cpp \
    source/gui/panel_ware_detail_editor.cpp \
    source/data_models/data_model_ware_specification.cpp \
    source/data_models/data_model_detail_search.cpp \
    source/gui/combobox_detail.cpp

HEADERS  += \
    source/app/application.h \
    source/app/application_log.h \
    source/app/application_params.h \
    source/logic/business_logic.h \
    source/gui/main_window.h \
    source/gui/widget_central.h \
    source/gui/panel_ware.h \
    source/gui/listview_ware.h \
    source/gui/panel_ware_detail.h \
    source/data_objects/data_ware.h \
    source/data_objects/data_collection.h \
    source/data_models/data_model_ware.h \
    source/gui/delegate_line_edit.h \
    source/gui/panel_ware_properties.h \
    source/gui/listview_ware_detail.h \
    source/gui/panel_ware_detail_editor.h \
    source/data_models/data_model_ware_specification.h \
    source/data_models/data_model_detail_search.h \
    source/gui/combobox_detail.h


MOC_DIR = ./xmoc

OBJECTS_DIR = ./xobj

RCC_DIR = ./xrcc

RESOURCES += \
    source/res/app.qrc

TRANSLATIONS += source/ts/strings_ru.ts
