import QtQuick 2.0

MouseArea {
	property int flag: 0x0;

	onPressed: {
		if (web_browser.isMaximized) {
			web_browser.showNormal();
		}

		timer.start();
	}

	Timer {
		id: timer;
		interval: 10;

		onTriggered: {
			var win_pos = mapToItem(win, mouseX, mouseY);
			var global_pos = mapToGlobal(win_pos.x, win_pos.y);
			web_browser.beginWindowMove(global_pos.x, global_pos.y, flag);
		}
	}
}
