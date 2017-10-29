import QtQuick 2.0

Rectangle {
	id: root;

	y: beginY;
	anchors.left: parent.left;
	anchors.right: parent.right;
	height: Math.round(50 * _ratio);

	color: "#ffffff";

	property bool is_bottom: false;
	property real beginY;
	property real endY;

	states: [
		State {
			name: "hidden";
			PropertyChanges {
				target: root;
				y: endY;
			}
		},
		State {
			name: "shown";
			PropertyChanges {
				target: root;
				y: beginY;
			}
		}
	]

	transitions: [
		Transition {
			from: "hidden,shown"
			to: "shown,hidden"
			NumberAnimation {
				property: "y";
				duration: 250 * anim_time_multiplier;
			}
		}
	]

	function show () {
		state = "shown";
		timer.start();
	}

	Rectangle {
		id: line;
		anchors.left: parent.left;
		anchors.right: parent.right;
		anchors.bottom: is_bottom ? undefined : parent.bottom;
		height: Math.round(2 * _ratio);

		color: "#e5e5e5";
	}

	Text {
		anchors.left: parent.left;
		anchors.top: is_bottom ? line.bottom : parent.top;
		anchors.right: parent.right;
		anchors.bottom: is_bottom ? parent.bottom : line.top;

		verticalAlignment: Text.AlignVCenter;
		horizontalAlignment: Text.AlignHCenter;
		elide: Text.ElideRight;

		color: "#2a2a2a";
		font.pixelSize: Math.round(20 * _ratio);
		font.family: "Ubuntu";

		text: qsTr("Press again to add new session");
	}

	Timer {
		id: timer;
		interval: 1000;
		onTriggered: root.state = "hidden";
	}
}
