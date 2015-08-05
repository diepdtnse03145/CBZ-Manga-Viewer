TEMPLATE = app

QT += qml quick widgets gui-private gui

SOURCES += main.cpp \
    wpageprovider.cpp \
    wpagepool.cpp



RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    wpageprovider.h \
    wpagepool.h

CONFIG += C++14
