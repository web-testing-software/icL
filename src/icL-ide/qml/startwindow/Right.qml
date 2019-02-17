import QtQuick 2.0

Rectangle {
	id: right

	color: look.start.right.background

	Rectangle {
		id: rightHeader

		anchors {
			top: parent.top
			right: parent.right
			left: parent.left
		}

		height: rd(rq * 60)
		color: look.start.right.header.background

		Text {
			text: qsTr("Online sessions")

			anchors {
				verticalCenter: parent.verticalCenter
				left: parent.left
				leftMargin: rd(rq * 20)
			}

			color: look.start.right.header.foreground
			font.family: "icL"
			font.pixelSize: rd(rq * 21)
		}
	}
}

