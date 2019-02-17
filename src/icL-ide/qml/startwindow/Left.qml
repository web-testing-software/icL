import QtQuick 2.0

Rectangle {
    id: left

    color: look.start.left.background

    Rectangle {
        id: leftHeader

        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
        }

        height: rd(rq * 60)
        color: look.start.left.header.background

        Text {
            text: qsTr("Offline sessions")

            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: rd(rq * 20)
            }

            color: look.start.left.header.foreground
            font.family: "icL"
            font.pixelSize: rd(rq * 21)
        }
    }
}
