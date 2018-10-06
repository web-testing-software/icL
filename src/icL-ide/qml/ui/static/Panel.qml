import QtQuick 2.0

Rectangle {
	id: panel

	signal click

	property bool selected: false;

	color: {
		if (selected)
			return look.session.main.handleVisible
		else
			return look.session.main.handleHidden
	}

	MouseArea {
		anchors.fill: parent;
		onClicked: panel.click()
	}
}
