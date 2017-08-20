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
	property real anim_time_multiplier: 1;


	property color focus_color: "#003bc5";
	property real focus_hue: 0;

	function paste_menu (component, properties, x, y) {
		var menu = component.createObject(pastemenu, properties);
		pastemenu.menus.push(menu);
		pastemenu.visible = true;
		menu.show (x, y);
	}

	Logo {
		onClicked: paste_menu(about_menu, {}, mouseX, mouseY);
	}

//	MenuLightning {
//		id: menu_base;
//	}

	Component {
		id: about_menu;

		MenuLightning {
			//
		}
	}

	MouseArea {
		id: pastemenu;
		anchors.fill: parent;
		visible: false;

		property var menus: [];

		function requestRemove (menu) {
			var index = menus.indexOf(menu);
			menus.splice(index, 1);
			menu.destroy();

			if (menus.length == 0)
				visible = false;
		}

		onClicked: menus[0].progress = 0;
	}

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
