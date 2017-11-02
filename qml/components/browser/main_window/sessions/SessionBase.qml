import QtQuick 2.0

import "../";

import "qrc:/scripts/move_flags.js" as MOVE_FLAGS;

ResizeMoveMouseArea {
	id: root;
	width: win_rectangle.width;
	height: win_rectangle.height;

	layer.enabled: true;

	flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.V_MOVE;

	property Item prev: null;
	property Item next: null;
	property bool deleted: false;
	property bool shown: true;

	y: shown
	   ? 0
	   : (active_area.sessions_manage_mode
		  ? (prev == current_item
			 ? 0.45 * height
			 : !!prev && prev.prev == current_item
			   ? 0.9 * height
			   : height)
		  : height);

	onYChanged: {
		if (y == 0) {
			if (!!prev) {
				prev.visible = false;
			}
		}
		else if (y == height) {
			visible = false
		}
	}

	Behavior on y {
		NumberAnimation {
			duration: 250 * anim_time_multiplier;
		}
	}
}
