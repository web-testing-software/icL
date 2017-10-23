import QtQuick 2.0

MouseArea {
	id: root;
	property int flag: 0x0;
	property var win_pos;
	property var global_pos;

	onPressed: {
		win_pos = mapToItem(win, mouseX, mouseY);
		global_pos = mapToGlobal(win_pos.x, win_pos.y);

		if (web_browser.isMaximized) {
			timer.was_maximised = true;
			timer.last_location = mouseX;
			timer.last_width = width;
			web_browser.showNormal();
		}
		else {
			timer.was_maximised = false;
		}

		timer.start();
	}

	Timer {
		id: timer;
		interval: 10;

		property bool was_maximised: false;
		property real last_location: 0;
		property real last_width: 0;

		onTriggered: {
			var alpha = 0.0;
			if (was_maximised) {
				alpha = last_location > last_width - width / 2
						? 1 - (last_width - last_location) / width
						: last_location < width / 2
						  ? last_location / width
						  : 0.5;
			}
			web_browser.beginWindowMove(global_pos.x, global_pos.y, flag, was_maximised, alpha);
		}
	}
}
