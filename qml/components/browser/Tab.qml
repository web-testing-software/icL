import QtQuick 2.0

Item {
	id: root;
	height: parent.height;
	width: tab_container.tab_width;

	property var webview: null;
	property string default_name: "script_name.icl";
	property bool active: false;

	Image {
		id: favicon;
		sourceSize: Qt.size(22 * _ratio, 22 * _ratio);
		anchors.verticalCenter: parent.verticalCenter;
		anchors.left: parent.left;
		anchors.margins: 6 * _ratio;
		source: webview && webview.icon
				? webview.icon : "qrc:/images/blank_favicon.svg";
	}

	Text {
		id: tab_name;
		anchors.top: parent.top;
		anchors.bottom: parent.bottom;
		anchors.left: favicon.right;
		anchors.right: parent.right;
		anchors.leftMargin: 6 * _ratio;
		elide: Text.ElideRight;
		text: webview && webview.title !== webview.url
			  ? webview.title : default_name;
		font.family: "Ubuntu";
		verticalAlignment: Text.AlignVCenter;
		font.pointSize: 10 * _ratio;
		color: active ? focus_color : "#595959";
	}
}
