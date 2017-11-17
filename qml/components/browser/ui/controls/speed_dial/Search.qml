import QtQuick 2.9
import QtQuick.Controls 1.4

import "../" as Controls;
import "../../button_icons/" as ButtonIcons;

Base {
	id: root;
	anchors.leftMargin: Math.round(12 * _ratio);

	ButtonIcons.Search {
		id: search;

		anchors.right: parent.right;
		anchors.rightMargin: Math.round(6 * _ratio);
		anchors.verticalCenter: parent.verticalCenter;
	}

	Controls.TextInput {
		id: text_input;

		anchors.left: parent.left;
		anchors.right: search.left;
		// vertical aligment are not working (???)
		// anchors.verticalCenter: text_input.verticalCenter;
		y: (parent.height - height) * 0.5;
	}
}
