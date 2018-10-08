import QtQuick 2.0

Item {
	id: sessionWindow

	Rectangle {
		id: header

		anchors.left: parent.left
		anchors.right: parent.right
		anchors.top: parent.top
		height: rd(rq * 50)

		color: look.start.header.background

		Text {
			text: qsTr("Wellcome to icL!")

			anchors.centerIn: parent

			font.family: "icL"
			font.pixelSize: rd(rq * 24)
			color: look.start.header.foreground
		}

		MouseArea {
			anchors.fill: parent;

			property int winx: 0
			property int winy: 0
			property int beginx: 0
			property int beginy: 0

			onPressed: {
				winx = win.x
				winy = win.y
				beginx = winx + mouseX
				beginy = winy + mouseY
			}

			onMouseXChanged: {
				if (containsMouse) {
					var screenx = mouseX + win.x
					var screeny = mouseY + win.y

					win.x = winx + (screenx - beginx)
					win.y = winy + (screeny - beginy)
				}
			}
		}
	}

	Rectangle {
		id: left
	}

	Rectangle {
		id: right
	}

	Rectangle {
		id: bottom
	}

}
