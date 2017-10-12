import QtQuick 2.0

Item {
	property string current_webview_url: !!current_webview
										 ? current_webview.url
										 : "https://gitlab.com/lixcode/ic-lightning"; // For testing

	BarButton {
		id: back;
		source: "qrc:/images/back.svg";
		anchors.top: parent.top;
		anchors.left: parent.left;
		anchors.leftMargin: Math.round(6 * _ratio);
	}

	BarButton {
		id: stop_refresh;
		source: "qrc:/images/refresh.svg";
		anchors.top: parent.top;
		anchors.left: back.right;
	}

	BarButton {
		id: forward;
		source: "qrc:/images/forward.svg";
		anchors.top: parent.top;
		anchors.left: stop_refresh.right;
	}

	Image {
		id: adress_bar_icon;
		anchors.left: forward.right;
		anchors.leftMargin: Math.round(12 * _ratio);
		anchors.verticalCenter: forward.verticalCenter;
		source: "qrc:/images/adress_bar_icon.svg";
		sourceSize: Qt.size(Math.round(17 * _ratio), Math.round(17 * _ratio));
	}

	Text {
		id: host;
		text: current_webview_url.match(/^https?:\/\/\w+([\.\-]\w+)+/)[0];
		anchors.left: adress_bar_icon.right;
		anchors.leftMargin: Math.round(6 * _ratio);
		anchors.verticalCenter: adress_bar_icon.verticalCenter;
		color: focus_color;
		font.family: "Ubuntu";
	}

	Text {
		text: current_webview_url.substring(host.text.length);
		anchors.left: host.right;
		anchors.verticalCenter: host.verticalCenter;
		anchors.right: parent.right;
		anchors.rightMargin: Math.round(6 * _ratio);
		elide: Text.ElideRight;
		color: focus_color;
		font.family: "Ubuntu";
		opacity: 0.5;
	}
}
