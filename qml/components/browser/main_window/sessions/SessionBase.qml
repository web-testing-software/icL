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
		radius: Math.round(5 * _ratio);
		color: "#80000000";
	}

	flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.V_MOVE;

	property Item prev: null;
	property Item next: null;
	property bool deleted: false;
	property bool shown: true;

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
		}
	]

	state: shown
		   ? "shown"
		   : (active_area.sessions_manage_mode
			  ? (prev == current_item
				 ? "second"
				 : !!prev && prev.prev == current_item
				   ? "third"
				   : "hidden")
			  : "hidden");

	visible: (!next || next.y != 0) && y != height;

	transitions: [
		Transition {
			from: "shown,second,third,hidden,third,second";
			to: "second,third,hidden,third,second,shown";
			NumberAnimation {
				target: root;
				property: "y";
				duration: 250 * anim_time_multiplier;
			}
		}
	]
}
