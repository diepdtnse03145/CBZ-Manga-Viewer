import "../Component"
import QtQuick 2.0

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
