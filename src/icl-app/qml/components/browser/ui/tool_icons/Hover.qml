import QtQuick 2.0

Base {
	alpha: 0.0;

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
			alpha = 0.0;
		}
	}
}
