import QtQuick 2.6
import QtQuick.Controls 1.4

import "../" as Controls;
import "../../button_icons/" as ButtonIcons;

ButtonBase {
	id: root;
	anchors.leftMargin: Math.round(12 * _ratio);

	ButtonIcons.Search {
		id: search;

		anchors.right: parent.right;
		anchors.rightMargin: Math.round(6 * _ratio);
		anchors.verticalCenter: parent.verticalCenter;

		alpha: root.alpha;

		MouseArea {
			anchors.fill: parent;

			onClicked: text_input.forceActiveFocus();
		}
	}

	Controls.TextInput {
		id: text_input;

		anchors.left: parent.left;
		anchors.right: search.left;
		// vertical aligment are not working (???)
		// anchors.verticalCenter: text_input.verticalCenter;
		y: (parent.height - height) * 0.5;

		place_holder_text: qsTr("Type script name to search");
		place_holder_color: "#3e3e3e";

		onFocusChanged: {
			if (focus) {
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
}
