import QtQuick 2.0
import QtGraphicalEffects 1.0

MouseArea {
	id: root;

	x: 2 * _ratio;
	y: 2 * _ratio;
	width: height * 0.75;
	height: 40 * _ratio;
	clip: true;

	property bool active: false;

	Image {
		id: logo;
		source: "qrc:/images/icLightning.svg";
		sourceSize.width: root.width;
		sourceSize.height: root.height;
		visible: false;
	}

	Item {
		y: active ? 0 : -root.height;
		height: root.height * 2;

		Behavior on y {
			NumberAnimation {
				duration: 150;
			}
		}

		Colorize {
			id: logo_colored_2;
			source: logo_colored;
			width: logo.width;
			height: logo.height;

			hue: logo_colored.hue >= 0.5 ? logo_colored.hue - 0.5 : logo_colored.hue + 0.5;
			saturation: 1;
			lightness: 0;
		}

		Colorize {
			id: logo_colored;
			anchors.top: logo_colored_2.bottom;
			source: logo;
			width: logo.width;
			height: logo.height;

			hue: 0.6156;
			saturation: 1;
			lightness: 0;
		}
	}
}
