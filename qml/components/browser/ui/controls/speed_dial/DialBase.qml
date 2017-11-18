import QtQuick 2.0

import "../../" as Ui;

Ui.AnimatedIconIterface {
	id: root;

	width: Math.round(256 * _ratio);
	height: Math.round(146 * _ratio);

	activeFocusOnTab: true;

	alpha: containsMouse ? 1.0 : 0.0;

	Rectangle {
		id: background;
		anchors.fill: parent;

		color: "#ffffff";
		border.color: root.focus ? focus_color : "#e1e1e2";
		border.width: Math.round(2 * _ratio);
	}

	Image {
		id: thumnail;
		anchors.centerIn: parent;

		sourceSize {
			width: Math.round(250 * _ratio);
			height: Math.round(240.625 * _ratio);
		}
	}

	Rectangle {

		id: name_container;

		anchors.left: parent.left;
		anchors.right: parent.right;
		anchors.bottom: parent.bottom;
		height: Math.round(25 * _ratio);
	}
}
