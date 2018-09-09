import QtQuick 2.6

import "../../button_icons/" as ButtonIcons;

TextButton {
	id: root;
	text: qsTr("New");
	icon_item: icon;

	ButtonIcons.New {
		id: icon;
		alpha: root.alpha;
		anchors.left: parent.left;
	}
}
