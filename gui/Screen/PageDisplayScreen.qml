import "../Component"
import QtQuick 2.0

ScreenBase{
    id: root

    PageDisplay {
        id: page
        anchors.fill: parent
        source : CurrentBook.currentPage
        pageListModel: pageLists
        onNext: {
            CurrentBook.next()
        }

        onPrevious: {
            CurrentBook.previous()
        }

        onToPage: {
            CurrentBook.gotoPage(page)
        }
    }
}


