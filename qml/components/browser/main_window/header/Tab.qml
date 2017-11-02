import QtQuick 2.0

import "../../ui/highlighters";

TabHighlight {
	id: root;
	height: parent.height;
	width: tab_container.tab_width;
	clip: true;
	drawColor: border_color;

	property var webview: null;
	property string default_name: "script_name.icl";
	property bool active: false;

	Image {
		id: favicon;
		sourceSize: Qt.size(Math.round(22 * _ratio), Math.round(22 * _ratio));
		anchors.verticalCenter: parent.verticalCenter;
		anchors.left: parent.left;
		anchors.margins: root.width > Math.round(30 * _ratio) ? Math.round(6 * _ratio) : 0;
		source: webview && webview.icon
				? webview.icon : "qrc:/images/blank_favicon.svg";
	}

	Text {
		id: tab_name;
		anchors.top: parent.top;
		anchors.bottom: parent.bottom;
		anchors.left: favicon.right;
		anchors.right: parent.right;
		anchors.leftMargin: Math.round(6 * _ratio);
		elide: Text.ElideRight;
		text: webview && webview.title !== webview.url
			  ? webview.title : default_name;
		verticalAlignment: Text.AlignVCenter;
		font.pixelSize: Math.round(13.5 * _ratio);
		font.family: "Ubuntu";
		color: active ? focus_color : "#595959";
	}
}
