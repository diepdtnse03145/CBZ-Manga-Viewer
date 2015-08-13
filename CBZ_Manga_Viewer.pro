TEMPLATE = app

QT += qml quick widgets gui-private gui

SOURCES += main.cpp \
    CMV/wpagepool.cpp \
    CMV/CMV_UiHandler.cpp \
    CMV/CMV_DeviceInfo.cpp \
    CMV/UiModel/CMV_PageProvider.cpp \
    CMV/CMV_CurrentBook.cpp \
    CMV/CMV_Book.cpp \
    CMV/CMV_CbzBook.cpp

TARGET = CBZ_Manga_Reader

RESOURCES += \
    resource.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    CMV/wpagepool.h \
    CMV/CMV_UiHandler.h \
    CMV/CMV_Log.h \
    CMV/CMV_DeviceInfo.h \
    CMV/UiModel/CMV_PageProvider.h \
    CMV/CMV_CurrentBook.h \
    CMV/CMV_Book.h \
    CMV/CMV_CbzBook.h

CONFIG += C++14

INCLUDEPATH += CMV \
               CMV/UiModel

#CONFIG(release, debug|release) {
#    DEFINES += CMV_NO_DEBUG_OUTPUT
#}
