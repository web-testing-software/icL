import QtQuick 2.0
import icL.Toolkit 1.0
import icL 1.0

import "../utils" as Utils
import "../startwindow"

Item {
	id: sessionWindow

	Rectangle {
		id: header

		anchors {
			left: parent.left
			right: parent.right
			top: parent.top
		}

		height: rd(rq * 50)
		color: look.start.header.background

		Text {
			text: qsTr("Wellcome to icL!")

			anchors.centerIn: parent

			font.family: "icL"
			font.pixelSize: rd(rq * 24)
			color: look.start.header.foreground
		}

		Utils.MoveResizeArea {
			anchors.fill: parent
			flag: MoveFlags.hMove | MoveFlags.vMove
		}
	}

	Left {
		id: left

		anchors {
			top: header.bottom
			right: parent.horizontalCenter
			bottom: underline.top
			left: parent.left
		}
	}

	Right {
		id: right

		anchors {
			top: header.bottom
			right: parent.right
			bottom: parent.bottom
			left: parent.horizontalCenter
		}
	}

	Rectangle {
		id: underline

		anchors {
			left: parent.left
			right: parent.right
			bottom: parent.bottom
		}

		height: rd(rq * 24)
		color: look.start.underline.background

		Text {
			text: qsTr("icL 1.0.0 powered by Qt")
			color: look.start.underline.foreground
			font.family: "icL"
			font.pixelSize: rd(rq * 12.5)

			anchors {
				right: parent.right
				rightMargin: rd(rq * 8)
				verticalCenter: parent.verticalCenter
			}

			MouseArea {
				anchors.fill: parent
				cursorShape: Qt.PointingHandCursor

				onClicked: gateway.aboutQt();
			}
		}
	}

}
