import QtQuick 2.0

import ICLightning.Database 1.0

import "../../" as Ui;

Ui.AnimatedIconIterface {
	id: root;

	width: Math.round(256 * _ratio);
	height: Math.round(146 * _ratio);

	activeFocusOnTab: true;

	primaryColor: "#e1e1e2";
	secondaryColor: "#ffffff";
	alpha: (containsMouse || root.focus) && is_initialised ? 1.0 : 0.0;

	property DialDescription description: null;
	property bool is_initialised: !!description;

	Rectangle {
		id: background;
		anchors.fill: parent;

		color: "#ffffff";
		border.color: helper.linearMix(primaryColor, hoverColor, alpha);
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
		anchors.margins: Math.round(2 * _ratio);
		height: Math.round(25 * _ratio);

		color: is_initialised ? secondaryColor : primaryColor;

		Text {
			id: title_item;
			anchors.centerIn: parent;

			text: is_initialised ? description.title : qsTr("To be filled later");

			font.pixelSize: Math.round(16 * _ratio);
			font.family: "Ubuntu";
			color: "#3e3e3e";
		}
	}
}
