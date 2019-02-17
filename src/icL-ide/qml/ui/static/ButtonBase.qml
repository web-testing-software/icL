import QtQuick 2.0

Rectangle {
    id: buttonBase

    anchors.left: parent.left
    anchors.right: parent.right

    height: rd(rq * 85)

    property bool activeState: false
    property alias hovered: mousearea.containsMouse
    property alias text: textItem.text

    signal clicked

    state: {
        if (activeState)
            return hovered ? "active-hovered" : "active"
        else
            return hovered ? "hovered" : "normal"
    }

    Text {
        id: textItem

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: rd(rq * 6)

        font.family: "icL"
        font.pixelSize: rd(rq * 10.7)
    }

    MouseArea {
        id: mousearea

        anchors.fill: parent
        hoverEnabled: true

        onClicked: buttonBase.clicked()
    }

    states: [
        State {
            name: "normal"
            PropertyChanges {
                target: buttonBase
                color: look.session.main.button.normal.background
            }
            PropertyChanges {
                target: textItem
                color: look.session.main.button.normal.foreground
            }
        },
        State {
            name: "hovered"
            PropertyChanges {
                target: buttonBase
                color: look.session.main.button.hover.background
            }
            PropertyChanges {
                target: textItem
                color: look.session.main.button.hover.foreground
            }
        },
        State {
            name: "active"
            PropertyChanges {
                target: buttonBase
                color: look.session.main.button.active.background
            }
            PropertyChanges {
                target: textItem
                color: look.session.main.button.active.foreground
            }
        },
        State {
            name: "active-hovered"
            PropertyChanges {
                target: buttonBase
                color: look.session.main.button.activeHover.background
            }
            PropertyChanges {
                target: textItem
                color: look.session.main.button.activeHover.foreground
            }
        }
    ]
}
