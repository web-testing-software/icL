import QtQuick 2.9
import QtQuick.Window 2.3

Window {
	width: 100
	height: 100
	color: "red"

	visibility: "Windowed"
	visible: true

	// @disable-check M16
	onClosing: {
		gateway.closeSessionWindows();
	}
}
