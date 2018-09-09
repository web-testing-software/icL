import QtQuick 2.0
import QtWebEngine 1.3

import "../../ui/tool_icons" as ToolIcons;
import "../../ui/controls";

Item {
	property string current_webview_url: "about:blank";

	function setUrl(url) {
		console.log("url", url);
		host.update();
		data.update();
		current_webview_url = url;
	}

	function setLoading (loading) {
		stop_refresh.reversed = loading;
	}

	function setBack (bool) {
		back.reversed = bool;
	}

	function setForward (bool) {
		forward.reversed = bool;
	}

	ToolIcons.Back {
		id: back;
		anchors.top: parent.top;
		anchors.left: parent.left;
		anchors.leftMargin: Math.round(6 * _ratio);

		reversed: current_webview.canGoBack;
	}

	ToolIcons.RefreshStop {
		id: stop_refresh;
		anchors.top: parent.top;
		anchors.left: back.right;

		reversed: current_webview.loading;
	}

	ToolIcons.Forward {
		id: forward;
		anchors.top: parent.top;
		anchors.left: stop_refresh.right;

		reversed: current_webview.canGoForward;
	}

	Image {
		id: adress_bar_icon;
		smooth: false;
		anchors.left: forward.right;
		anchors.leftMargin: Math.round(12 * _ratio);
		anchors.verticalCenter: forward.verticalCenter;
		source: "qrc:/header/adress_bar_icon.svg";
		sourceSize: Qt.size(Math.round(17 * _ratio), Math.round(17 * _ratio));
	}

	Text {
		id: host;

		anchors.left: adress_bar_icon.right;
		anchors.leftMargin: Math.round(6 * _ratio);
		anchors.verticalCenter: adress_bar_icon.verticalCenter;
		color: focus_color;
		font.family: "Ubuntu";

		function update() {
			text = current_webview_url.match(/^(https?:\/\/\w+([\.\-]\w+)+|\w+:)/)[0];
		}
	}

	Text {
		id: data;

		anchors.left: host.right;
		anchors.verticalCenter: host.verticalCenter;
//		anchors.right: parent.right;
		anchors.rightMargin: Math.round(6 * _ratio);
//		elide: Text.ElideRight;
		color: focus_color;
		font.family: "Ubuntu";
		opacity: 0.5;

		function update() {
			text = current_webview_url.slice(host.text.length);
		}
	}
}
