import QtQuick 2.0

import "../ui" as UI
import "../ui/static" as Static

Rectangle {
	id: staticRoot

	width: rd(rq * 75)
	color: look.session.main.background

	UI.ImageButton {
		id: menuOpenButton

		width: rd(rq * 75)
		height: rd(rq * 40)
		source: look.path + "icL.svg"
	}

	Static.Button {
		anchors.top: menuOpenButton.bottom

		text: qsTr("Browser")
		source: look.path + "browser.svg"
	}
}
