import QtQuick 2.0

Image{
    id:img
    source: "image://pages/green"

    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.debug(img.width,img.height)
        }
    }
}
