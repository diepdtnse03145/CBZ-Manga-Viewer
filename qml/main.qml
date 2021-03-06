import QtQuick 2.5
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id:root
    height: 960
    width: 640
    visible: true

    function loadScreen(screenSource){
        prev.source = next.source
        next.source = screenSource
        console.debug("Change to: "+screenSource)
        startChangeScreen()
    }

    function startChangeScreen(){
        screenChange.restart()
    }

    Loader{
        id: prev
    }

    Loader{
        id: next
    }

    ParallelAnimation {
        id: screenChange
        running: false

        PropertyAnimation {
            id: prevAni
            target: prev
            property: "x"
            from: 0
            to: -640
            easing.type: Easing.InCubic
            duration: 500
        }

        PropertyAnimation {
            id: nexAni
            target: next
            property: "x"
            from: 640
            to: 0
            easing.type: Easing.InCubic
            duration: 500
        }
    }
}
