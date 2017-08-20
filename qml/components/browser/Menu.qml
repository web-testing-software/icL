import QtQuick 2.0

MouseArea {
	anchors.fill: parent;

	Rectangle {
		width: row.width;
		height: row.height;

		color: "#800000";
	}

	Row {
		id: row;
		Item {
			width: Math.round(30 * _ratio);
			height: parent.height;
		}
		Column {
			MenuOption {}
			MenuOption {}
			MenuOption {}
			MenuOption {}
		}
	}
}
