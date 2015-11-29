import QtQuick 2.5
import QtQuick.Controls 1.4
import "qrc:/Component/"

ScreenBase{
    id: root

    ScrollView{
        anchors.top: topPanel.bottom
        anchors.left: root.left
        anchors.right: root.right
        anchors.bottom: root.bottom
        ListView{
            anchors.fill: parent
            clip:true
            model: bookLists
            delegate: BookManagerListDelegate{

            }
        }
    }

    TopPanel{
        id: topPanel
        anchors.top: root.top
        anchors.left: root.left
        anchors.right: root.right
        text: "Book Manager"
        opacity: 1
    }
}


