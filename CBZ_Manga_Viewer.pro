QT += qml quick widgets gui-private gui

CONFIG += C++14
TEMPLATE = app

HEADERS += \
    CMV/Book/CMV_Book.h \
    CMV/Book/CMV_CbzBook.h \
    CMV/ScreenManager/CMV_ScreenDefine.h \
    CMV/ScreenManager/CMV_ScreenManager.h \
    CMV/UiModel/CMV_BookCoverProvider.h \
    CMV/UiModel/CMV_BookManagerListModel.h \
    CMV/UiModel/CMV_PageListModel.h \
    CMV/UiModel/CMV_PageListProvider.h \
    CMV/UiModel/CMV_PageProvider.h \
    CMV/CMV_BookManager.h \
    CMV/CMV_CurrentBook.h \
    CMV/CMV_DeviceInfo.h \
    CMV/CMV_Log.h \
    cbzmangaviewer.h

SOURCES += \
    CMV/Book/CMV_Book.cpp \
    CMV/Book/CMV_CbzBook.cpp \
    CMV/ScreenManager/CMV_ScreenManager.cpp \
    CMV/UiModel/CMV_BookCoverProvider.cpp \
    CMV/UiModel/CMV_BookManagerListModel.cpp \
    CMV/UiModel/CMV_PageListModel.cpp \
    CMV/UiModel/CMV_PageListProvider.cpp \
    CMV/UiModel/CMV_PageProvider.cpp \
    CMV/CMV_BookManager.cpp \
    CMV/CMV_CurrentBook.cpp \
    CMV/CMV_DeviceInfo.cpp \
    cbzmangaviewer.cpp \
    main.cpp

RESOURCES += \
    qml/qml.qrc \
    icon/icon.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

INCLUDEPATH += CMV \
               CMV/UiModel \
               CMV/Book \
               CMV/ScreenManager


#DEFINES += \
##           CMV_NO_ELTIMER   \
#           CMV_NO_DEBUG_OUTPUT


#CONFIG(release, debug|release) {
#    DEFINES += CMV_NO_DEBUG_OUTPUT
#}

