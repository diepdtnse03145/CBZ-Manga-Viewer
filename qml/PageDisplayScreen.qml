import QtQuick 2.5

import "qrc:/Component/"

ScreenBase{
    id: root

    PageDisplay {
        id: page
        anchors.fill: parent
        source : CurrentBook.currentPage

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
            onClicked: {
                if (root.onscreenSource == ""){
                    root.onscreenSource = "qrc:/Screen/PageListOnscreen.qml"
                } else {
                    root.onscreenSource = ""
                }

                console.debug(root.onscreenSource)
            }
        }

    }

}


