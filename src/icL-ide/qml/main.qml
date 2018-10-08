import QtQuick 2.0
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

import icL.Look 1.0
import icL.Toolkit 1.0

import "main" as Main

Window {
	id: win

	width: 800
	height: 600

	visible: true
	visibility: Window.Maximized

	// [!] Scale begin

	// Scale all the interface
	// ratio qualifier
	property real rq: (Screen.pixelDensity / 4.03) * gateway.userInterfaceScale

	// round decimal numbers
	function rd(pixels) {
		return Math.round(pixels)
	}

	Component.onCompleted: {
		gateway.requestToCloseSessionWindows.connect(win.close);
	}

	// [!] Scale end

	property int ready: 0;

	// Global objects
	Look {
		id: look

		Component.onCompleted: {
			clone(gateway.crossLook)
			loadConf(":/themes/light.json", false);
		}
	}

	Panels {
		id: panels
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
