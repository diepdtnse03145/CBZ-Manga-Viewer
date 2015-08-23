import QtQuick 2.0

Image{
    id:root

    signal next()
    signal previous()
    signal toPage(int page)

    property alias pageListModel : pageList.model

    MouseArea{
        x: root.width / 3 * 2
        y: 0
        width: root.width / 3
        height: root.height
        onClicked: {
            root.next()
        }
    }

    MouseArea{
        x: 0
        y: 0
        width: root.width / 3
        height: root.height
        onClicked: {
            root.previous()
            console.debug("back")
        }
    }

    MouseArea{
        x: root.width / 3
        y: 0
        width: root.width / 3
        height: root.height
        onClicked: {
            console.debug("Show")
            pageList.visible  = !pageList.visible
            topPanel.visible = !topPanel.visible
        }
    }

    Rectangle{
        id: topPanel
        x: 0
        y: 0
        width: root.width
        height: 50
        color: "green"
        visible: false
        opacity: 0.5
        MouseArea{
            anchors.fill: parent
            onClicked: {
                ScreenManager.toManager()
            }
        }
    }

    ListView {
        id: pageList
        x: 0
        y: root.height / 4 * 3
        width: root.width
        height: root.height / 4
        clip:true
        orientation: ListView.Horizontal
        delegate: PageListDelegate {
            onClicked: {
                root.toPage(page)
            }
        }

        visible : false
    }
}
