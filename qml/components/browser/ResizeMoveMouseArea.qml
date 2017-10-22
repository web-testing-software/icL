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
			web_browser.showNormal();
			timer.was_maximised = true;
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

		onTriggered: {
			web_browser.beginWindowMove(global_pos.x, global_pos.y, flag, was_maximised);
		}
	}
}
