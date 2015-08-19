import QtQuick 2.0

PageDisplay {
    id: page
    anchors.fill: parent
    source : Book.currentPage
    pageListModel: pageLists
    onNext: {
        Book.nextPage()
    }

    onPrevious: {
        Book.previousPage()
    }

    onToPage: {
        Book.gotoPage(page)
    }
}
