import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id:root
    title: qsTr("CBZ")
    height: 960
    width: 640
    visible: true
    Image{
        id:img
        source: Book.currentPage
        anchors.fill:parent

        MouseArea{
            x: parent.width / 3
            y: 0
            width: (parent.width / 3) * 2
            height: parent.height
            onClicked: {
                Book.nextPage()
            }
        }

        MouseArea{
            x: 0
            y: 0
            width: parent.width / 3
            height: parent.height
            onClicked: {
                Book.previousPage()
            }
        }
    }
}
