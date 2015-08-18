import QtQuick 2.0

Rectangle {
    height: 100
    width: 640

    Image {
        id: image1
        x: 0
        y: 0
        width: 100
        height: 100
        source: cover
    }

    Text {
        id: text1
        x: 101
        y: 0
        width: 422
        height: 49
        text: name
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 101
        y: 55
        width: 422
        height: 45
        text: type
        font.pixelSize: 12
    }

    Text {
        id: text3
        x: 565
        y: 55
        width: 67
        height: 45
        text: size
        font.pixelSize: 12
    }
}
