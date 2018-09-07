import QtQuick 2.0

Item {
	id: root;

	anchors.leftMargin: Math.round(6 * _ratio);
	anchors.verticalCenter: parent.verticalCenter;

	width: Math.round(20 * _ratio);
	height: width;

	property real alpha: 0.0;
	property bool reversed: false;
	property color drawColor: "#3e3e3e";
}
