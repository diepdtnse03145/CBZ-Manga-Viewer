TEMPLATE = app

QT += qml quick widgets gui-private gui

SOURCES += main.cpp \
    CMV/CMV_UiHandler.cpp \
    CMV/CMV_DeviceInfo.cpp \
    CMV/UiModel/CMV_PageProvider.cpp \
    CMV/CMV_CurrentBook.cpp \
    CMV/UiModel/CMV_PageListModel.cpp \
    CMV/UiModel/CMV_PageListProvider.cpp \
    CMV/Book/CMV_Book.cpp \
    CMV/Book/CMV_CbzBook.cpp \
    CMV/UiModel/CMV_BookManagerListModel.cpp \
    CMV/CMV_BookManager.cpp \
    CMV/UiModel/CMV_BookCoverProvider.cpp

TARGET = CBZ_Manga_Reader

RESOURCES += \
    resource.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    CMV/CMV_UiHandler.h \
    CMV/CMV_Log.h \
    CMV/CMV_DeviceInfo.h \
    CMV/UiModel/CMV_PageProvider.h \
    CMV/CMV_CurrentBook.h \
    CMV/UiModel/CMV_PageListModel.h \
    CMV/UiModel/CMV_PageListProvider.h \
    CMV/Book/CMV_Book.h \
    CMV/Book/CMV_CbzBook.h \
    CMV/UiModel/CMV_BookManagerListModel.h \
    CMV/CMV_BookManager.h \
    CMV/UiModel/CMV_BookCoverProvider.h

CONFIG += C++14

INCLUDEPATH += CMV \
               CMV/UiModel \
               CMV/Book

#CONFIG(release, debug|release) {
#    DEFINES += CMV_NO_DEBUG_OUTPUT
#}

