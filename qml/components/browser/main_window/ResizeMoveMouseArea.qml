import QtQuick 2.5

MouseField {
	id: root;
	property int flag: 0x0;
	property var win_pos;

	onPressed: {
		if (mouse.button == Qt.LeftButton) {
			resize_move_timer.flag = flag;

			win_pos = mapToItem(win, mouseX, mouseY);
			resize_move_timer.global_pos = Qt.point(win_pos.x + web_browser.x, win_pos.y + web_browser.y);

			if (web_browser.isMaximized) {
				resize_move_timer.was_maximised = true;
				resize_move_timer.last_location = mouseX;
				resize_move_timer.last_width = width;
				web_browser.showNormal();
			}
			else {
				resize_move_timer.was_maximised = false;
			}

			resize_move_timer.start();
		}
	}
}
