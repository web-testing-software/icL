import QtQuick 2.0

ButtonBase {
    id: button

    property alias source: image.source

    ImageButton {
        id: image

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: rd(rq * 6)

        switcher: activeState
    }
}
