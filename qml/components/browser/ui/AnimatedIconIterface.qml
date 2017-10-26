import QtQuick 2.0

MouseArea {
	id: root;

	property real alpha: reversed ? 1.0 : 0.0;
	property bool reversed: false;
	property color primaryColor: "#bbbbbb";
	property color secondaryColor: "#5b5b5b";
	property color hoverColor: focus_color;
	property color drawColor: alpha > 1
							   ? helper.mix(secondaryColor, hoverColor, alpha - 1)
							   : helper.mix(primaryColor, secondaryColor, alpha);

	hoverEnabled: true;
	onClicked: reversed = !reversed;

	Behavior on alpha {
		NumberAnimation {
			duration: 250 * anim_time_multiplier;
		}
	}
}
