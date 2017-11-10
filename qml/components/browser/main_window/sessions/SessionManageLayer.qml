import QtQuick 2.0

import "../" as MainWindow

MainWindow.MouseField {
	anchors.fill: parent;
	visible: manage_mode;

	onWheel: {
		if (wheel.angleDelta.y < 0) {
			sessions_list.to_next();
		}
		else {
			sessions_list.to_prev();
		}
	}

	onClicked: {
		if (current_item == root) {
			sessions_list.exit_manage_mode(0);
		}
		else if (current_item.next == root) {
			sessions_list.exit_manage_mode(1);
		}
		else {
			sessions_list.exit_manage_mode(2);
		}
	}
}
