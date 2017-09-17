import QtQuick 2.0

Item {
	id: root;
	height: parent.height;
	width: tab_container.tab_width;

	property var webview: null;

	Image {
		id: favicon;
		sourceSize: Qt.size(22 * _ratio, 22 * _ratio);
		anchors.verticalCenter: parent.verticalCenter;
		anchors.left: parent.left;
		anchors.margins: 6 * _ratio;
		source: webview && webview.icon ? webview.icon : "qrc:/images/blank_favicon.svg";
	}
}
