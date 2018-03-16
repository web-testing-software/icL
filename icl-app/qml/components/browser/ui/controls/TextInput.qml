import QtQuick 2.6

TextInput {
	id: text_input;

	leftPadding: Math.round(6 * _ratio);
	rightPadding: Math.round(10 * _ratio);
	font.pixelSize: Math.round(18.5 * _ratio);
	font.family: "Ubuntu";
	color: "#3e3e3e";

	activeFocusOnTab: true;
	activeFocusOnPress: true;
	selectByMouse: true;
	selectedTextColor: focus_color;
	selectionColor: "#f2f2f2";
	persistentSelection: true;

	property alias place_holder_color: place_holder.color;
	property alias place_holder_text: place_holder.text;

	Text {
		id: place_holder;
		visible: !text_input.focus && text_input.text.length == 0;

		font: text_input.font;
		x: Math.round(6 * _ratio);
	}

	cursorDelegate: Component {
		Rectangle {
			id: cursor;
			width: Math.round(2 * _ratio);
			color: focus_color;

			opacity: text_input.focus ? 1.0 : 0.0;
			visible: opacity != 0;

			SequentialAnimation {
				running: text_input.focus;
				loops: Animation.Infinite;

				NumberAnimation {
					target: cursor;
					property: "opacity";
					from: 1.0;
					to: 0.01;
					duration: 800;
				}
				NumberAnimation {
					target: cursor;
					property: "opacity";
					from: 0.01;
					to: 1.0;
					duration: 100;
				}
			}
		}
	}
}
