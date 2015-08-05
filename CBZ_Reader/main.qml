import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id:root
    title: qsTr("CBZ Manga Viewer")
    height: 960
    width: 640
    visible: true
    Image{
        id:img
        source: Book.currentPage
        anchors.fill:parent

        MouseArea{
            anchors.fill: parent
            onClicked: {
                Book.next()
            }
        }
    }

}
