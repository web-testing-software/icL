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

			activeState: true
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
				id: panelsItem

				width: rd(rq * 59)
				height: rd(rq * 59)

				anchors.horizontalCenter: parent.horizontalCenter
				anchors.top: parent.top
				anchors.topMargin: rd(rq * 6)

				Item {
					id: panelsBrowserH
					anchors.fill: parent

					Static.Panel {
						id: browserLeftH

						anchors.top: parent.top
						anchors.bottom: parent.bottom
						anchors.left: parent.left

						selected: panels.browser.leftPanel
					}

					Static.Panel {
						id: browserNavigationH

						anchors.top: parent.top
						anchors.left: browserLeftH.right
						anchors.leftMargin: rd(rq * 4)
						anchors.right: parent.right

						selected: panels.browser.navigationBar
					}

					Static.Panel {
						id: browserCenterH

						anchors.top: browserNavigationH.bottom
						anchors.topMargin: rd(rq * 4)
						anchors.bottom: parent.bottom
						anchors.horizontalCenter: parent.horizontalCenter

						selected: true
					}

					Static.Panel {
						id: browserDevH

						anchors.top: browserNavigationH.bottom
						anchors.topMargin: rd(rq * 4)
						anchors.bottom: parent.bottom
						anchors.right: parent.right

						selected: panels.browser.devTools
					}
				}

				Rectangle {
					color: look.session.main.handle

					width: rd(rq * 12)
					height: rd(rq * 12)

					x: (parent.width - width) * 0.5
					y: (parent.height - height) * 0.5

					radius: width * 0.5
				}
			}

			text: qsTr("Panels")
		}
	}
}
