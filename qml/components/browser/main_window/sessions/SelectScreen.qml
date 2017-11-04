import QtQuick 2.0

import "../"

import "../../../../scripts/my_enums.js" as ME;
import "qrc:/scripts/move_flags.js" as MOVE_FLAGS;

SessionBase {
	id: root;

	transformOrigin: Item.Top;
	layer.enabled: true;

	property bool add_after_current: true;

	Component.onCompleted: show("show", ME.SELECT_SCREEN_TYPE_PROFILE);

	Rectangle {
		anchors.fill: parent;
		color: "#e5e5e5";
	}

	ResizeMoveMouseArea {
		anchors.fill: parent;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.V_MOVE;
	}

	function show (_state, what) {

		switch (what) {
		case ME.SELECT_SCREEN_TYPE_PROFILE:
			profile_ss.forceActiveFocus();
			break;
		}

		switch (_state) {
		case "top":
		case "add_after":
			transformOrigin = Item.Top;
			break;

		case "bottom":
		case "add_before":
			transformOrigin = Item.Bottom;
			break;

		case "key_trigger":
			transformOrigin = Item.Center;
			break;
		}

		state = _state;
		state = "show";
	}

	function hide () {
		transformOrigin = Item.Center;
		state = "hide";
	}

	Image {
		id: bg_icon;

		anchors.centerIn: parent;
		source: "qrc:/images/bg_icon.svg";
		sourceSize: Qt.size(Math.round(400 * _ratio), Math.round(400 * _ratio));
	}

	ProfileSelectScreen {
		id: profile_ss;
	}

	Image {
		id: qt_logo;
		source: "qrc:/images/qt_logo.svg";
		sourceSize: Qt.size(Math.round(54.5 * _ratio), Math.round(40 * _ratio));
		anchors.right: parent.right;
		anchors.bottom: parent.bottom;
		anchors.margins: Math.round(10 * _ratio);
	}

	Text {
		id: powered_by;
		anchors.right: qt_logo.left;
		anchors.rightMargin: Math.round(10 * _ratio);
		anchors.verticalCenter: qt_logo.verticalCenter;

		text: qsTr("Powered by");
		font.pixelSize: Math.round(18 * _ratio);
		font.family: "Ubuntu";
	}

	states: [
		State {
			name: "show";
			PropertyChanges {
				target: root;
				y: 0;
				scale: 1.0;
				opacity: 1;
			}
		},
		State {
			name: "hide";
			PropertyChanges {
				target: root
				scale: 1.2;
				opacity: 0;
			}
		},
		State {
			name: "top";
			PropertyChanges {
				target: root;
				y: 25 * _ratio;
				scale: 0.0;
			}
		},
		State {
			name: "bottom";
			PropertyChanges {
				target: root;
				y: -25 * _ratio;
				scale: 0.0;
			}
		},
		State {
			name: "add_after";
			PropertyChanges {
				target: root;
				opacity: 0;
				y: 0;
				scale: (root.height - 50 * _ratio) / root.height;
			}
		},
		State {
			name: "add_before";
			PropertyChanges {
				target: root;
				opacity: 0;
				y: 50 * _ratio;
				scale: (root.height - 50 * _ratio) / root.height;
			}
		},
		State {
			name: "key_trigger";
			PropertyChanges {
				target: root
				opacity: 0;
				scale: 0.8;
			}
		}
	]

	transitions: [
		Transition {
			from: "top,bottom,add_after,add_before";
			to: "show";
			NumberAnimation {
				properties: "y,scale,opacity";
				duration: 250 * anim_time_multiplier;
			}
		}/*,
		Transition {
			from: "show"
			to: "hide"
			NumberAnimation {
				properties: "scale,opacity";
				duration: 250 * anim_time_multiplier;
			}
		}*/
	]
}
