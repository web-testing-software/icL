import QtQuick 2.9
import QtQuick.Window 2.3

import icL.Look 1.0

Window {
	width: rd(rq * 800)
	height: rd(rq * 600)

	visible: true
	visibility: gateway.startWindowMode ? Window.Windowed : Window.Hidden

	// [!] Scale begin

	// Scale all the interface
	// ratio qualifier
	property real rq: (Screen.pixelDensity / 4.03) * gateway.userInterfaceScale

	// round decimal numbers
	function rd(pixels) {
		return Math.round(pixels)
	}

	// [!] Global objects

	Look {
		id: look

		Component.onCompleted: {
			gateway.crossLook = this;
		}
	}

	MouseArea {
		anchors.fill: parent;

		onClicked: gateway.startWindowMode = !gateway.startWindowMode
	}

	// [!] Content

	Rectangle {
		id: header

//		color: look.
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

	// @disable-check M16
	onClosing: {
		gateway.closeSessionWindows();
	}
}
