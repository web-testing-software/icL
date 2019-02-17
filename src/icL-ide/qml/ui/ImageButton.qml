import QtQuick 2.0

Item {
    id: imageButton

    clip: true

    property bool pressed: false
    property alias source: image.source
    property alias hover: mousearea.containsMouse

    signal clicked

    Image {
        id: image

        x: hover ? -parent.width : 0
        y: pressed ? -parent.height : 0
        sourceSize: Qt.size(parent.width * 2.0, parent.height * 2.0)
    }

    MouseArea {
        id: mousearea
        anchors.fill: parent
        hoverEnabled: true

        onClicked: imageButton.clicked()
    }
}
