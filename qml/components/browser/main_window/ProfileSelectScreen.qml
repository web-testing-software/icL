import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
	id: root;
	anchors.fill: parent;

	Item {
		id: avatar;
		width: Math.round(300 * _ratio);
		height: width;
		anchors.centerIn: parent;

		Image {
			id: avatar_mask;
			sourceSize: Qt.size(avatar.width, avatar.height);
			source: "qrc:/images/avatar_mask.svg";
			visible: false;
		}

		Image {
			id: avatar_image;
			sourceSize: avatar_mask.sourceSize;
			source: "qrc:/images/default_avatar.svg";
			visible: false;
		}

		OpacityMask {
			id: final_avatar;
			anchors.fill: parent;
			source: avatar_image;
			maskSource: avatar_mask;
		}

		DropShadow {
			anchors.fill: parent;
			source: final_avatar;
			radius: Math.round(4 * _ratio);
			color: "#80000000";
			verticalOffset: Math.round(2 * _ratio);
		}
	}

	Text {
		id: username;
		text: qsTr("Default");
		anchors.horizontalCenter: avatar.horizontalCenter;
		anchors.top: avatar.bottom;
		color: "#3a3a3a";

		font.family: "Ubuntu";
		font.pixelSize: Math.round(50 * _ratio);
	}

	DropShadow {
		anchors.fill: username;
		source: username;
		radius: Math.round(2 * _ratio)
		color: "#d0000000";
		verticalOffset: Math.round(2 * _ratio);
	}
}
