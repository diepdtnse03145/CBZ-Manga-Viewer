import QtQuick 2.0

ListView{
    anchors.fill: parent
    clip:true
    model: bookLists
    delegate: BookManagerListDelegate{

    }
}
