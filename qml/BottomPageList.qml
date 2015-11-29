import QtQuick 2.5

ListView {
    id: pageList
    x: 0
    y: root.height / 4 * 3
    width: root.width
    height: root.height / 4
    model: pageLists
    clip:true
    orientation: ListView.Horizontal
    delegate: PageListDelegate {
        onClicked: {
            CurrentBook.gotoPage(page)
        }
    }

}
