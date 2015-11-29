import QtQuick 2.5

Rectangle{
    id:root
    height: 960
    width: 640
    visible: true
    property alias onscreenSource: onscreenLoader.source
    Loader{
        z : 999
        id: onscreenLoader
        anchors.fill: parent
    }
}

