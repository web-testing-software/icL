import QtQuick 2.0

import "../../ui/tool_icons" as ToolIcons;
import "../../ui/controls";

Item {
	property string current_webview_url: !!current_webview
										 ? current_webview.url
										 : "https://gitlab.com/lixcode/ic-lightning"; // For testing

	ToolIcons.Back {
		id: back;
		anchors.top: parent.top;
		anchors.left: parent.left;
		anchors.leftMargin: Math.round(6 * _ratio);
	}

	ToolIcons.RefreshStop {
		id: stop_refresh;
		anchors.top: parent.top;
		anchors.left: back.right;
	}

	ToolIcons.Forward {
		id: forward;
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
