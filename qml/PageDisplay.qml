import QtQuick 2.0

Image{
    id:root

    signal next()
    signal previous()
    signal toPage(int page)

    property alias pageListModel : pageList.model

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
