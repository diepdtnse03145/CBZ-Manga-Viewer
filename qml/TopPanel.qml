import QtQuick 2.5

Rectangle{
    id: root
    height: 50
    color: "black"
    opacity: 0.75

    property alias text: screenName.text
    Text {
        id: screenName
        anchors.centerIn: parent
        color: "white"
    }
}

