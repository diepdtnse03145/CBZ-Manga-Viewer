import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id:root
    height: 960
    width: 640
    visible: true
//    PageDisplay {
//        id: page
//        anchors.fill: parent
//        source : Book.currentPage
//        pageListModel: pageLists
//        onNext: {
//            Book.nextPage()
//        }

//        onPrevious: {
//            Book.previousPage()
//        }

//        onToPage: {
//            console.debug("To page:" + page)
//            Book.gotoPage(page)
//        }
//    }

    ListView{
        anchors.fill: parent
        clip:true
        model: bookLists
        delegate: BookManagerListDelegate{
        }
    }
}
