import QtQuick 2.9
import QtQuick.Window 2.3

import icL.Look 1.0
import icL.Editor 1.0

import "../main" as Main

Window {
	id: win
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

//	color: "red"

	// [!] Global objects

	FontLoader {
		source: "qrc:/fonts/NotoSans-Regular.ttf"
		name: "icL"
	}

	Look {
		id: look

		editor.style{
			fontS: rd(rq * 16.5)
			lineS: rd(rq * 2)
		}

		Component.onCompleted: {
			gateway.crossLook = this
		}
	}

	// [!] Content
	Main.StartWindow {
		id: sessionWindow
		anchors.fill: parent
	}

	// @disable-check M16
	onClosing: {
		gateway.closeSessionWindows()
	}

	Component.onCompleted: {
//		flags = flags | Qt.FramelessWindowHint
	}

	// This timer fix bug for maximised window
	Timer {
		id: resizeMoveTimer;
		interval: 10;
		running: false
		repeat: false

		property var resizeMoveArea;

		onTriggered: resizeMoveArea.pressedDelayFunction();
	}

	Editor {
		anchors.fill: parent

		style: look.editor.style
		chars: look.editor.chars

		Component.onCompleted: {
			intern.loadFile("test.txt")
			updateNow()
		}
	}
}
