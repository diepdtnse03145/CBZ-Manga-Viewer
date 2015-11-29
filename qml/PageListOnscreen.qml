import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import "qrc:/Component/"

Item{
    id: root
    ScrollView{
        x: 0
        y: root.height / 4 * 3
        width: root.width
        height: root.height / 4
        ListView {
            id: pageList
            anchors.fill: parent
            model: pageLists
            clip:true
            orientation: ListView.Horizontal
            delegate: PageListDelegate {
                onClicked: {
                    CurrentBook.gotoPage(page)
                }
            }

        }
    }



    TopPanel{
        id: topPanel
        anchors.top: root.top
        anchors.left: root.left
        anchors.right: root.right
        height: 50
        visible: true
        text: CurrentBook.name()

        Button {
            id: button1
            x: 15
            y: 15
            text: qsTr("Button")
            iconSource: "qrc:/icon/bookManager.png"
            opacity: 1
            onClicked: {
                ScreenManager.viewerToManager()
            }
        }
    }
}
