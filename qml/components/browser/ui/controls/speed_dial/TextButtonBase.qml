import QtQuick 2.0

Base {
	id: root;
	anchors.leftMargin: Math.round(12 * _ratio);
	activeFocusOnTab: true;

	onClicked: {
		forceActiveFocus();
	}

	onFocusChanged: {
		if (focus) {
			alpha = 1.0;
		}
		else {
			if (!containsMouse) {
				alpha = 0.0;
			}
		}
	}

	onContainsMouseChanged: {
		if (containsMouse) {
			if (alpha == 0.0) {
				reversed = false;
			}
			alpha = 1.0;
		}
		else {
			if (alpha == 1.0) {
				reversed = true;
			}
			if (!focus) {
				alpha = 0.0;
			}
		}
	}
}
