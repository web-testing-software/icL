import QtQuick 2.0
import QtGraphicalEffects 1.0

MouseArea {
	id: root;

	x: Math.round(2 * _ratio);
	y: Math.round(web_browser.isMaximized ? -4 : 2 * _ratio);
	width: height * 0.75;
	height: Math.round(40 * _ratio);
	clip: true;

	property bool active: false;

	Image {
		id: logo;
		source: "qrc:/images/icLightning.svg";
		sourceSize.width: root.width;
		sourceSize.height: root.height;
		visible: false;
	}

	Colorize {
		id: logo_colored;
		source: logo;
		anchors.fill: logo;

		hue: focus_hue;
		saturation: 1;
		lightness: 0;
	}
}
