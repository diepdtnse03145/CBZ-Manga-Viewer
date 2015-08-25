import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id:root
    height: 960
    width: 640
    visible: true

    Loader{
        anchors.fill: parent
        id: screenLoader
        source: ScreenManager.currentScreenSource
    }
}
