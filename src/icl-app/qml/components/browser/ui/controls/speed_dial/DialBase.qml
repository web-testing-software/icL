import QtQuick 2.7

import icL.DB 1.0

import "../../" as Ui;

Ui.AnimatedIconIterface {
	id: root;

	width: Math.round(256 * _ratio);
	height: Math.round(146 * _ratio);

	activeFocusOnTab: true;

	primaryColor: "#e1e1e2";
	secondaryColor: "#e6ffffff";
	alpha: (containsMouse || root.focus) && is_initialised ? 1.0 : 0.0;

	property DialDescription description: null;
	property bool is_initialised: !!description;
	property bool is_ok: true;

	function update_dial_thumbnail () {
		is_ok = true;
		thumnail.source = "";
		thumnail.source = thumnail.url_str;
	}

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
		source: url_str;

		property string url_str: is_initialised ? "file:///" + cache_dir +
												  description.url + ".png" : "" ;

		sourceSize {
			width: Math.round(250 * _ratio);
			height: Math.round(140.625 * _ratio);
		}

		onStatusChanged: {
			if (status == Image.Error) {
				is_ok = false;
				update_dial_icon(url_str.substring(8), description.url);
			}
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
