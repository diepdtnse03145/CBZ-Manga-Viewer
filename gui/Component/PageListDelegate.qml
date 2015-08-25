import QtQuick 2.0

Item{
    id:root
    width: img.width
    height: parent.height

    signal clicked(int page)

    Image{
        id:img
        width: sourceSize.width
        height: sourceSize.height
        anchors.bottom: parent.bottom
        source: pageName
    }
    MouseArea{
        anchors.fill :parent
        onClicked: {
            root.clicked(index)
        }
    }
}
