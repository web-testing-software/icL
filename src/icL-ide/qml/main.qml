import QtQuick 2.0
import QtQuick.Window 2.3
import QtQuick.Controls 1.4

import "main" as Main

Window {
	id: win

	width: 800
	height: 500

	visible: true
	visibility: Window.Maximized

	// Scale all the interface
	property real _rm: 1.0 //< manual resize of interface
	property real rq: 1.0 * _rm //< ratio qualifier

	// round decimal numbers
	function rd(pixels) {
		return Math.round(pixels)
	}

	Main.Static {
		id: staticPanel

		anchors {
			top: parent.top
			left: parent.left
			bottom: parent.bottom
		}

		height: 300
	}

	SplitView {
		id: leftCentralSplit
		orientation: Qt.Horizontal

		anchors {
			top: parent.top
			left: staticPanel.right
			bottom: parent.bottom
		}

		Main.LeftPanel {
			id: leftPanel
		}

		Main.CentralSide {
			id: centralSide
		}

		Keys.onPressed: {
			if (event.text === "-") {
				_rm -= 0.1
			} else if (event.text === "+") {
				_rm += 0.1
			}
		}

		Component.onCompleted: forceActiveFocus()
	}
}
