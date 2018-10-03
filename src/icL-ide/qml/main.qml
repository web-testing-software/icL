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
	property real _rm: 1.0
	property real _rq: 1.0 * _rm
	function rq(pixels) {
		return Qt.binding(function () {
			return Math.round(pixels * _rq)
		})
	}

	Main.Static {
		id: staticPanel

		anchors: {
			top: parent.top
			left: parent.left
			right: parent.right
		}
	}

	SplitView {
		id: leftCentralSplit
		orientation: Qt.Horizontal

		anchors: {
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
	}
}
