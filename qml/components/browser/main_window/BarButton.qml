import QtQuick 2.0

Item {
	id: root;
	anchors.margins: Math.round(8 * _ratio);
	anchors.leftMargin: Math.round(12 * _ratio);
	width: Math.round(20 * _ratio);
	height: width;

	property alias source: img.source;

	function click () {
		// Do nothing
	}

	Image {
		id: img;
		sourceSize: Qt.size(root.width, root.height);
	}

	MouseArea {
		anchors.fill: parent;
		onClicked: root.click();
		preventStealing: true;
		propagateComposedEvents: true;
	}
}
