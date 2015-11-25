import QtQuick 2.0

Image{
    id: root
    signal pressed()
    MouseArea{
        anchors.fill: parent
        onPressed: {
            root.pressed()
        }
    }
}

