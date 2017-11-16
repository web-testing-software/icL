import QtQuick 2.0
import QtGraphicalEffects 1.0

import "../";

import "qrc:/scripts/move_flags.js" as MOVE_FLAGS;

ResizeMoveMouseArea {
	id: root;
	width: win_rectangle.width;
	height: win_rectangle.height;

	layer.enabled: true;
	layer.effect: DropShadow {
		horizontalOffset: 0;
		verticalOffset: 0;
		radius: root.visible ? Math.round(5 * _ratio) : 0;
		color: "#80000000";
	}

	flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.V_MOVE;

	property Item prev: null;
	property Item next: null;
	property bool deleted: false;
	property bool shown: true;

	property bool self_visible: true;
	property bool next_visible: true;

	property bool updated: false;

	states: [
		State {
			name: "shown";
			PropertyChanges {
				target: root;
				y: 0;
			}
		},
		State {
			name: "second";
			PropertyChanges {
				target: root;
				y: Math.round(0.4 * height);
			}
		},
		State {
			name: "third";
			PropertyChanges {
				target: root;
				y: Math.round(0.9 * height);
			}
		},
		State {
			name: "hidden"
			PropertyChanges {
				target: root;
				y: height;
			}
		},
		State {
			name: "closed"
			PropertyChanges {
				target: root
				y: Math.round(0.4 * height);
				x: width
			}
		}
	]

	state: "shown";

	function updateState () {
		if (shown) {
			state = "shown";
		}
		else {
			if (manage_mode) {
				if (prev == current_session) {
					state = "second";
				}
				else if (!!prev && prev.prev == current_session) {
					state = "third";
				}
				else {
					state = "hidden";
				}
			}
			else {
				state = "hidden";
			}
		}
	}

	onShownChanged: updateState();

	visible: self_visible && next_visible;

	onYChanged: {
		self_visible = y < height;

		if (!!prev){
			prev.next_visible = y != prev.y;
		}
	}

	onXChanged: {
		if (x == width) {
			root.destroy();
		}
	}

	transitions: [
		Transition {
			from: "shown,second,third,hidden,third,second";
			to: "second,third,hidden,third,second,shown";
			NumberAnimation {
				target: root;
				property: "y";
				duration: 240 * anim_time_multiplier;
			}
		}
	]
}
