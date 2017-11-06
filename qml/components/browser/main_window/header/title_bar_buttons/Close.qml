import QtQuick 2.0

import "../../../ui/tool_icons" as ToolIcons;

ToolIcons.Close {
	anchors.margins: Math.round(4 * _ratio);
	primaryColor: "#55505c";
	secondaryColor: "#b60000";
	hoverColor: "#55505c";

	onClicked: web_browser.close();
}
