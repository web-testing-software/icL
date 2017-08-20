import QtQuick 2.0
import QtWebEngine 1.5
import QtQuick.Window 2.3

import "components/browser";
import "components/browser/contextmenu";

Rectangle {
	id: win;
	color: "#ffe";

	property string app_version: "1.0.0 dev";

	property real _ratio: Screen.pixelDensity / 5.5;
	property color focus_color: "#003bc5";
	property real focus_hue: 0;

	Logo {
		onClicked: menu_base.show(mouseX, mouseY);
	}

	MenuLightning {
		id: menu_base;
	}


//	Window {
//		id: menu_win;
//		visible: false;
//		flags: Qt.FramelessWindowHint;
//		width: menu.width;
//		height: menu.height;

////		on

//		Menu {
//			id: menu
//			//
//		}
//	}

//	MouseArea {
//		width: 300 * _ratio;
//		height: 50;

//		onClicked: console.log(width, height);
//	}

//	WebEngineView {
//		anchors.fill: parent;
//		anchors.topMargin: 50;

//		url: "http://disk.yandex.ru";

//		settings.autoLoadImages: false;
//		settings.javascriptCanOpenWindows: false;
//		profile.persistentCookiesPolicy: WebEngineProfile.NoPersistentCookies;

//		onTitleChanged: console.log("Title changed:" + title);
//	}
}
