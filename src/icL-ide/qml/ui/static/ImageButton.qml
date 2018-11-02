import QtQuick 2.0

Item {
	id: imageButton

	width: rd(rq * 59)
	height: rd(rq * 59)

	clip: true

	property bool switcher: false
	property alias source: image.source

	Image {
		id: image

		x: switcher ? -parent.width : 0
		sourceSize: Qt.size(parent.width * 2.0, parent.height)
	}
}
