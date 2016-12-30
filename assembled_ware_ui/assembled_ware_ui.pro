
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = assembled_ware_ui
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += source/app \
				source/gui \
				source/logic \
				source/data_objects \
				source/data_models \
				source/utils \
				/home/u122/projects/redis/hiredis \
				../qt_redis

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
    source/gui/combobox_detail.cpp \
    ../../../redis/hiredis/async.c \
    ../../../redis/hiredis/dict.c \
    ../../../redis/hiredis/hiredis.c \
    ../../../redis/hiredis/net.c \
    ../../../redis/hiredis/read.c \
    ../../../redis/hiredis/sds.c \
    ../qt_redis/qt_redis_sync_connection.cpp \
    source/gui/line_edit_ware_name.cpp \
    source/utils/ware_name_text2.cpp

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
    source/gui/combobox_detail.h \
    ../../../redis/hiredis/async.h \
    ../../../redis/hiredis/dict.h \
    ../../../redis/hiredis/fmacros.h \
    ../../../redis/hiredis/hiredis.h \
    ../../../redis/hiredis/net.h \
    ../../../redis/hiredis/read.h \
    ../../../redis/hiredis/sds.h \
    ../../../redis/hiredis/sdsalloc.h \
    ../qt_redis/qt_redis_sync_connection.h \
    source/gui/line_edit_ware_name.h \
    source/utils/ware_name_text2.h


MOC_DIR = ./xmoc

OBJECTS_DIR = ./xobj

RCC_DIR = ./xrcc

RESOURCES += \
    source/res/app.qrc

TRANSLATIONS += source/ts/strings_ru.ts
