import QtQuick 2.0
import icL.Toolkit 1.0

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

		MouseTrack {
			id: mtrack

			onPositionChanged: marea.move(position);
		}

		MouseArea {
			id: marea
			anchors.fill: parent;

			property point winxy: Qt.point(0, 0)
			property point beginxy: Qt.point(0, 0)

			onPressed: {
				winxy = Qt.point(win.x, win.y)
				beginxy = mtrack.startTracking()
			}

			onReleased: move(mtrack.stopTracking());

			function move(pos) {
				win.x = winxy.x + (pos.x - beginxy.x)
				win.y = winxy.y + (pos.y - beginxy.y)
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
