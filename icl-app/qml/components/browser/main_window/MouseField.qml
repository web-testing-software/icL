import QtQuick 2.5

MouseArea {
	hoverEnabled: true;
	preventStealing: true;
	scrollGestureEnabled: true;
	propagateComposedEvents: false;
	acceptedButtons: Qt.LeftButton | Qt.MiddleButton | Qt.RightButton;
}
