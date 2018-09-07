import QtQuick 2.0
import QtGraphicalEffects 1.0

import "../../ui/controls";

Item {
	id: root;
	anchors.fill: parent;

	function add_new_session () {
//		select_screen.state = "shown2";
		select_screen.z = 999;
		sessions_list.add_new_session();
	}

	Item {
		id: avatar;
		width: Math.round(200 * _ratio);
		height: width;
		anchors.centerIn: parent;

		Image {
			id: avatar_mask;
			smooth: false;
			sourceSize: Qt.size(avatar.width, avatar.height);
			source: "qrc:/content/avatar_mask.svg";
			visible: false;
		}

		Image {
			id: avatar_image;
			smooth: false;
			sourceSize: avatar_mask.sourceSize;
			source: "qrc:/content/default_avatar.svg";
			visible: false;
		}

		OpacityMask {
			id: final_avatar;
			anchors.fill: parent;
			source: avatar_image;
			maskSource: avatar_mask;
		}
	}

	Text {
		id: username;
		text: qsTr("Default");
		anchors.horizontalCenter: avatar.horizontalCenter;
		anchors.top: avatar.bottom;
		anchors.topMargin: Math.round(10 * _ratio);
		color: "#3a3a3a";

		font.family: "Ubuntu";
		font.pixelSize: Math.round(35 * _ratio);
	}

	Button {
		text: qsTr("Create session");
		color: focus_color;
		pixelSize: Math.round(20 * _ratio);
		anchors.top: username.bottom;
		anchors.topMargin: Math.round(10 * _ratio);
		anchors.horizontalCenter: username.horizontalCenter;

		onClicked: add_new_session();
	}

	Keys.onReturnPressed: add_new_session();
}
