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

	Column {
		anchors.top: menuOpenButton.bottom
		anchors.left: parent.left
		anchors.right: parent.right

		Static.Button {
			text: qsTr("Browser")
			source: look.path + "browser.svg"
		}

		Static.Button {
			text: qsTr("Code")
			source: look.path + "code.svg"
		}

		Static.Button {
			text: qsTr("Debug")
			source: look.path + "debug.svg"
		}
	}

	Column {
		anchors.bottom: parent.bottom
		anchors.left: parent.left
		anchors.right: parent.right

		Static.Button {
			text: qsTr("Run")
			source: look.path + "run.svg"
		}

		Static.Button {
			text: qsTr("Debug")
			source: look.path + "rundebug.svg"
		}

		Static.ButtonBase {
			Item {
				id: panels

				width: rd(rq * 59)
				height: rd(rq * 59)

				Item {
					id: panels1

					Static.Panel {
						//
					}
				}
			}

			text: qsTr("Panels")
		}
	}
}
