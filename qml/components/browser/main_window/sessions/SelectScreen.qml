import QtQuick 2.0
import QtGraphicalEffects 1.0

import "../"

import "../../../../scripts/my_enums.js" as ME;
import "qrc:/scripts/move_flags.js" as MOVE_FLAGS;

SessionBase {
	id: root;

	transformOrigin: Item.Top;
	layer.enabled: true;

	visible: ((!next || next.y > 0) && z == 0) || z > 0;
	layer.effect: null;

	property point center: Qt.point(width / 2, height / 2);
	property real max_radius: Math.max(width, height);
	property real progress: 1.0;

	property var add_after: root;

	state: "shown";

	function update_copy () {
		// This function is not actually for Select Screen, just for browser or driver sessions
	}

//	Component.onCompleted: show("shown", ME.SELECT_SCREEN_TYPE_PROFILE);
	function updateState () {
		state = "shown2";
	}

	function show (after, _state, what) {

		manage_mode = false;
		add_after = after;

		switch (what) {
		case ME.SELECT_SCREEN_TYPE_PROFILE:
			profile_ss.forceActiveFocus();
			break;
		}

		state = _state;
		z = 999;
		state = "shown2";
	}

	function hide () {
		state = "hidden0";
	}

	onProgressChanged: {
		if (progress == 0.0 && state == "hidden0") {
			z = 1;
			state = "shown2";
		}
		canvas_mask.requestPaint();
	}

	states: [
		State {
			name: "hidden0";
			PropertyChanges {
				target: root;
				progress: 0.0;
			}
		},
		State {
			name: "hidden1";
			PropertyChanges {
				target: root;
				progress: 0.0;
			}
		},
		State {
			name: "shown2";
			PropertyChanges {
				target: root;
				progress: 1.0;
			}
		}
	]

	transitions: [
		Transition {
			from: "shown2,hidden1"
			to: "hidden0,shown2"

			NumberAnimation {
				target: root;
				property: "progress"
				duration: 240 * anim_time_multiplier;
			}
		}/*,
		Transition {
			from: ""
			to: ""

			NumberAnimation {
				target: root;
				property: "progress"
				duration: 240 * anim_time_multiplier;
			}
		}*/
	]

	Item {
		id: content;
		anchors.fill: parent;
		visible: !opacity_mask.visible;

		Rectangle {
			anchors.fill: parent;
			color: "#e5e5e5";
		}

		ResizeMoveMouseArea {
			anchors.fill: parent;
			flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.V_MOVE;
		}

		Image {
			id: bg_icon;

			smooth: false;
			anchors.centerIn: parent;
			source: "qrc:/images/bg_icon.svg";
			sourceSize: Qt.size(Math.round(400 * _ratio), Math.round(400 * _ratio));
		}

		ProfileSelectScreen {
			id: profile_ss;
		}

		Image {
			id: qt_logo;
			smooth: false;
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
	}

	Canvas {
		id: canvas_mask;
		anchors.fill: parent;
		layer.enabled: true;

		onPaint: {
			var ctx = getContext("2d");
			var radius = max_radius * progress;
			var radius2 = radius * progress;

			ctx.clearRect(0, 0, root.width, root.height);

			if (current_item == root && !!next) {
				ctx.fillRect(0, 0, width, next.y);
			}

			ctx.beginPath();
			ctx.fillStyle = "rgba(255, 255, 255, 0.5)";
			ctx.moveTo(center.x, center.y - radius);
			ctx.lineTo(center.x + radius, center.y);
			ctx.lineTo(center.x, center.y + radius);
			ctx.lineTo(center.x - radius, center.y);
			ctx.fill();


			ctx.beginPath();
			ctx.fillStyle = "rgba(255, 255, 255, 1)";
			ctx.moveTo(center.x, center.y - radius2);
			ctx.lineTo(center.x + radius2, center.y);
			ctx.lineTo(center.x, center.y + radius2);
			ctx.lineTo(center.x - radius2, center.y);
			ctx.fill();
		}

		visible: false;
	}

	OpacityMask {
		id: opacity_mask;
		anchors.fill: parent;
		source: content;
		maskSource: canvas_mask;
		visible: progress != 1.0;
//		visible: false;
	}

	SessionManageLayer {
		onClicked: add_after = root;
	}

}
