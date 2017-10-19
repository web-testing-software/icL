import QtQuick 2.0

Rectangle {
	id: root;

	width: Math.round(24 * _ratio);
	height: Math.round(24 * _ratio);
	color: mouse_area.containsMouse ? "#ffdedede" : "#00f2f2f2";
	radius: Math.round(12 * _ratio);

	property string icon: "";

	function click () {}

	Image {
		id: icon_img
		anchors.centerIn: parent;
		source: root.icon;
		sourceSize: Qt.size(Math.round(20 * _ratio), Math.round(14 * _ratio));
	}

	MouseArea {
		id: mouse_area;
		anchors.fill: parent;
		hoverEnabled: true;
		onClicked: root.click();
	}
}
