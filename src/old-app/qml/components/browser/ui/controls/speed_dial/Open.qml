import QtQuick 2.6

import "../../button_icons/" as ButtonIcons;

TextButton {
	id: root;
	text: qsTr("Open");
	icon_item: icon;

	ButtonIcons.Open {
		id: icon;
		alpha: root.alpha;
		anchors.left: parent.left;
	}
}
