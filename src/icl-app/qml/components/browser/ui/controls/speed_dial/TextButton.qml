import QtQuick 2.0

TextButtonBase {
	id: root;
	width: text_item.x + text_item.width + anchors.leftMargin;

	property Item icon_item: null;
	property alias text: text_item.text;

	Text {
		id: text_item;
		anchors.left: icon_item.right;
		anchors.leftMargin: Math.round(6 * _ratio);
		anchors.top: parent.top;
		anchors.bottom: parent.bottom;
		font.pixelSize: Math.round(18.5 * _ratio);
		font.family: "Ubuntu";
		verticalAlignment: Text.AlignVCenter;
		color: "#3e3e3e";
	}
}
