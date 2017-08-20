import QtQuick 2.0

Item {
	id: root;
	width: txt_item.width + 30 * _ratio;
	height: txt_item.height + 20 * _ratio;

	property string text: "Option";

	Text {
		x: 15 * _ratio;
		y: 10 * _ration;
		id: txt_item;
		font.pixelSize: 16 * _ratio;
		text: root.text;
	}
}
