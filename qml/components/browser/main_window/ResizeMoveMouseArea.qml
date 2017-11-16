import QtQuick 2.5

import "../../../scripts/move_flags.js" as MF;

MouseField {
	id: root;
	property var win_pos;
	property bool was_maximised: false;
	property point global_pos;
	property point win_begin_xy;
	property size win_begin_size;
	property int last_location;
	property int last_win_width;
	property int flag;
	property int flag_copy: 0x0;

	onPressed: {
		if (mouse.button == Qt.LeftButton) {
			win_pos = mapToItem(null, mouseX, mouseY);
			global_pos = Qt.point(win_pos.x + win.x, win_pos.y + win.y);

			if (win.isMaximized) {
				was_maximised = true;
				last_location = mouseX;
				last_win_width = win.width;
				win.showNormal();
			}
			else {
				was_maximised = false;
			}
		}

		resize_move_timer.resize_move_area = root;
		resize_move_timer.start();
	}

	function pressedDelayFunction () {

		flag_copy = flag;
		win_begin_xy = Qt.point(win.x, win.y);
		win_begin_size = Qt.size(win.width, win.height);

		if (was_maximised) {
			var alpha = last_location > last_win_width - width / 2
					? 1 - (last_win_width - last_location) / width
					: last_location < width / 2
					  ? last_location / width
					  : 0.5;

			win_begin_xy.x = global_pos.x - win.width * alpha;
			win_begin_xy.y = global_pos.y - Math.min(win_pos.y, win.height);
		}
	}

	onPositionChanged: {
		if (flag_copy == 0x0) {
			return;
		}

		win_pos = mapToItem(null, mouseX, mouseY);
		var screenPos	= Qt.point(win_pos.x + win.x, win_pos.y + win.y);
		var	dx			= screenPos.x - global_pos.x;
		var	dy			= screenPos.y - global_pos.y;
		var	newX		= win_begin_xy.x;
		var	newY		= win_begin_xy.y;
		var	newWidth	= win_begin_size.width;
		var	newHeight	= win_begin_size.height;
		var	hResize		= (flag & MF.H_RESIZE) != 0;
		var	vResize		= (flag & MF.V_RESIZE) != 0;
		var	hMove		= (flag & MF.H_MOVE) != 0;
		var	vMove		= (flag & MF.V_MOVE) != 0;

		if (hResize) {
			newWidth += hMove ? -dx : dx;
			if (newWidth < win.minimumWidth) {
				newWidth = win.minimumWidth;
			}
		}

		if (vResize) {
			newHeight += vMove ? -dy : dy;
			if (newHeight < win.minimumHeight) {
				newHeight = win.minimumHeight;
			}
		}

		if (hMove) {
			newX += hResize ? win_begin_size.width - newWidth : dx;
		}

		if (vMove) {
			newY += vResize ? win_begin_size.height - newHeight : dy;
		}

		win.x = newX;
		win.y = newY;
		win.width = newWidth;
		win.height = newHeight;
	}

	onReleased: {
		flag_copy = 0x0;
		if (resize_move_timer.running) {
			resize_move_timer.stop();
		}
	}
}
