import QtQuick 2.0

Rectangle {
	id: panel

	width: rd(rq * 17)
	height: rd(rq * 17)
	radius: rd(rq * 8)

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
