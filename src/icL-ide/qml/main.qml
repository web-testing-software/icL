import QtQuick 2.0
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

import icL.Look 1.0

import "main" as Main

Window {
	id: win

	width: 800
	height: 500

	visible: true
	visibility: Window.Maximized

	// [!] Scale begin

	// Scale all the interface
	property real _rm: 1.0 //< manual resize of interface
	property real rq: 1.0 * _rm //< ratio qualifier

	// round decimal numbers
	function rd(pixels) {
		return Math.round(pixels)
	}

	// [!] Scale end

	property int ready: 0;

	// Global objects
	Look {
		id: look

		Component.onCompleted: {
			loadConf(":/themes/light.json", false);
		}
	}

	// Window content
	Main.Static {
		id: staticPanel

		anchors {
			top: parent.top
			left: parent.left
			bottom: parent.bottom
		}
	}

	SplitView {
		id: leftCentralSplit
		orientation: Qt.Horizontal

		anchors {
			top: parent.top
			left: staticPanel.right
			right: parent.right
			bottom: parent.bottom
		}

		Main.LeftPanel {
			id: leftPanel

			width: 250 // load from settings

			Layout.minimumWidth: rd(rq * 100)
			Layout.maximumWidth: rd(rq * 400)
		}

		Main.CentralSide {
			id: centralSide

			Layout.fillWidth: true
			Layout.minimumWidth: rd(rq * 800)
		}
	}
}
