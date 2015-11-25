import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "qrc:/Component/"

ScreenBase{
    id: root

    PageDisplay {
        id: page
        anchors.fill: parent
        source : CurrentBook.currentPage
        pageListModel: pageLists

        MouseArea{
            x: page.width / 3 * 2
            y: 0
            width: page.width / 3
            height: page.height
            onClicked: {
                CurrentBook.next()
            }
        }

        MouseArea{
            x: 0
            y: 0
            width: page.width / 3
            height: page.height
            onClicked: {
                CurrentBook.previous()
                console.debug("back")
            }
        }

        MouseArea{
            x: page.width / 3
            y: 0
            width: page.width / 3
            height: page.height
            onClicked: {/*
                console.debug("Show")
                pageList.visible  = !pageList.visible
                topPanel.visible = !topPanel.visible*/
            }
        }

        onToPage: {
            CurrentBook.gotoPage(page)
        }
    }

    TopPanel{
        id: topPanel
        anchors.top: root.top
        anchors.left: root.left
        anchors.right: root.right
        height: 50
        visible: true

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


