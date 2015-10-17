import "../Component"
import QtQuick 2.0

ScreenBase{
    id: root

    ListView{
        anchors.fill: parent
        clip:true
        model: bookLists
        delegate: BookManagerListDelegate{

        }
    }
}


