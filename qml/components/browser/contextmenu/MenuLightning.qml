import QtQuick 2.0

MenuBase {
	id: root;
	content: lightning;
	width: Math.round(200 * _ratio);
	height: Math.round(230 * _ratio);

	property real border_weight: Math.round(2 * _ratio);
	property color border_color: "#e1e1e1";
	property color bg_color: "white";

	Item {
		id: lightning;
		anchors.fill: parent;
		visible: progress == 1.0;

		// Borders

		Rectangle {
			id: border_l;
			anchors.top: parent.top;
			anchors.bottom: parent.bottom;
			width: border_weight;
			color: border_color;
		}

		Rectangle {
			id: border_tt;
			anchors.left: logo.left;
			anchors.right: logo.right;
			height: border_weight;
			color: border_color;
		}

		Rectangle {
			id: border_rl;
			anchors.top: parent.top;
			anchors.bottom: logo.bottom;
			anchors.left: logo.right;
			width: border_weight;
			color: border_color;
		}

		Rectangle {
			id: border_tb;
			anchors.left: logo.right;
			anchors.right: parent.right;
			anchors.top: logo.bottom;
			height: border_weight;
			color: border_color;
		}

		Rectangle {
			id: border_r;
			anchors.right: parent.right;
			anchors.top: border_tb.bottom;
			anchors.bottom: parent.bottom;
			width: border_weight;
			color: border_color;
		}

		Rectangle {
			id: border_b;
			anchors.left: border_l.right;
			anchors.right: border_r.left;
			anchors.bottom: parent.bottom;
			height: border_weight;
			color: border_color;
		}

		// Backgroud

		Rectangle {
			id: bg_t;
			anchors.top: border_tt.bottom;
			anchors.left: border_l.right;
			anchors.right: border_rl.left;
			anchors.bottom: border_tb.bottom;
			color: bg_color;

			MouseArea {
				anchors.fill: parent;
				onClicked: {
					fixCenterTo(mouseX + bg_t.x, mouseY + bg_t.y);
					progress = 0;
				}
			}
		}

		Rectangle {
			id: bg_b;
			anchors.top: border_tb.bottom;
			anchors.left: border_l.right;
			anchors.right: border_r.left;
			anchors.bottom: border_b.top;
			color: bg_color;

			MouseArea {
				anchors.fill: parent;
				onClicked: {
					fixCenterTo(mouseX + bg_b.x, mouseY + bg_b.y);
					progress = 0;
				}
			}
		}

		// Content

		Image {
			id: logo;
			anchors.top: border_tt.bottom;
			anchors.left: border_l.right;
			source: "qrc:/images/icLightning_black.svg";
			sourceSize: Qt.size(Math.round(30 * _ratio), Math.round(40 * _ratio));
		}

		Text {
			id: icLightning;
			anchors.top: bg_b.top;
			anchors.topMargin: Math.round(10 * _ratio);
			anchors.horizontalCenter: bg_b.horizontalCenter;
			text: "intracloudLightning";
			color: focus_color;
			font.pixelSize: Math.round(17.5 * _ratio);
			font.family: "Ubuntu";

			MouseArea {
				anchors.fill: parent;
				onClicked: Qt.openUrlExternally("https://gitlab.com/lixcode/ic-lightning");
				cursorShape: Qt.PointingHandCursor;
			}
		}

		Text {
			id: version;
			anchors.top: icLightning.bottom;
			anchors.bottomMargin: Math.round(5 * _ratio);
			anchors.horizontalCenter: icLightning.horizontalCenter;
			text: qsTr("version") + " " + app_version;
			color: "#7e7e7e";
			font.pixelSize: Math.round(11 * _ratio);
			font.family: "Ubuntu";
		}

		Text {
			anchors.left: bg_b.left;
			anchors.right: bg_b.right;
			anchors.verticalCenter: bg_b.verticalCenter;
			wrapMode: Text.WrapAtWordBoundaryOrAnywhere;
			horizontalAlignment: Text.AlignHCenter;
			color: "black";
			text: qsTr("A web driver for everyone");
			font.pixelSize: Math.round(19 * _ratio);
			font.family: "Ubuntu";
		}

		Text {
			id: designed_by;
			anchors.bottom: author.top;
			anchors.margins: Math.round(1 * _ratio);
			anchors.left: bg_b.left;
			anchors.right: bg_b.right;
			text: qsTr("Designed and programmed by");
			wrapMode: Text.WrapAtWordBoundaryOrAnywhere;
			horizontalAlignment: Text.AlignHCenter;
			color: "#7e7e7e";
			font.pixelSize: Math.round(11 * _ratio);
			font.family: "Ubuntu";
		}

		Text {
			id: author;
			anchors.bottom: bg_b.bottom;
			anchors.bottomMargin: Math.round(10 * _ratio);
			anchors.horizontalCenter: bg_b.horizontalCenter;
			text: "Lelițac Vasile";
			color: focus_color;
			font.pixelSize: Math.round(17.5 * _ratio);
			font.family: "Ubuntu";

			MouseArea {
				anchors.fill: parent;

				onClicked: Qt.openUrlExternally("https://vk.com/lixcode");
				cursorShape: Qt.PointingHandCursor;
			}
		}
	}
}
