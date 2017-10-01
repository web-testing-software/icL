import QtQuick 2.0
import QtWebEngine 1.5
import QtQuick.Window 2.3
import QtGraphicalEffects 1.0

import "components/browser";
import "components/browser/contextmenu";

Rectangle {
	id: win;
	color: "#fff";

	property string app_version: "1.0.0 dev";
	property real _ratio: Math.max(Screen.pixelDensity, 5.5) / 5.5;
	property real anim_time_multiplier: 1;


	property color focus_color: "#003bc5";
	property real focus_hue: 0.62;

	property color border_color: "#e1e1e2";

	function paste_menu (component, properties, x, y) {
		var menu = component.createObject(pastemenu, properties);
		pastemenu.menus.push(menu);
		pastemenu.visible = true;
		menu.show (x, y);
	}

	Rectangle {
		id: top_side;
		anchors.top: parent.top;
		anchors.left: parent.left;
		anchors.right: parent.right;
		height: Math.round(44 * _ratio);
		color: "#f5f5f5";

		Rectangle {
			anchors.left: parent.left;
			anchors.right: parent.right;
			anchors.bottom: parent.bottom;
			height: 2 * _ratio;
			color: border_color;
		}

		Logo {
			id: logo;
			onClicked: paste_menu(about_menu, {}, mouseX, mouseY);
		}

		Item {
			id: top_tab_bar;
			anchors.left: logo.right;
			anchors.top: parent.top;
			anchors.right: parent.right;
			anchors.bottom: parent.bottom;
			anchors.leftMargin: Math.round(4 * _ratio);
			anchors.rightMargin: Math.round(4 * _ratio);

			property variant current_tab: test_tab;

			Rectangle {
				anchors.bottom: parent.bottom;
				height: 36 * _ratio;
				x: top_tab_bar.current_tab.x;
				width: top_tab_bar.current_tab.width;

				Rectangle {
					id: tb;
					anchors.top: parent.top;
					anchors.left: parent.left;
					anchors.right: parent.right;
					color: border_color;
					height: 2 * _ratio;
				}

				Rectangle {
					id: lb;
					anchors.top: tb.bottom;
					anchors.left: parent.left;
					anchors.bottom: parent.bottom;
					color: border_color;
					width: 2 * _ratio;
				}

				Rectangle {
					id: rb;
					anchors.top: tb.bottom;
					anchors.right: parent.right;
					anchors.bottom: parent.bottom;
					color: border_color;
					width: 2 * _ratio;
				}
			}

			Row {
				id: tab_container;
				height: 34 * _ratio;
				anchors.left: parent.left;
				anchors.bottom: parent.bottom;

				property int max_tab_width: 300 * _ratio;
				property int tab_number: 3;
				property int tab_width: tab_number * max_tab_width + new_tab_button.width <= parent.width
										? max_tab_width
										: (parent.width - new_tab_button.width) / tab_number;

				Tab {
					id: test_tab;
					active: true;
				}
				Tab {
//					id: test_tab;
				}
				Tab {
//					id: test_tab;
				}
			}

			Item {
				id: new_tab_button;
				width: 34 * _ratio;
				height: 34 * _ratio;

				anchors.left: tab_container.right;
				anchors.bottom: parent.bottom;

				Image {
					id: new_tab;
					source: "qrc:/images/new_tab.svg";
					sourceSize: Qt.size(14 * _ratio, 14 * _ratio);
					anchors.centerIn: parent;
				}

				Colorize {
					id: new_tab_colored;
					source: new_tab;
					anchors.fill: new_tab;

					hue: focus_hue;
					saturation: 1;
					lightness: 0;
				}
			}
		}
	}

	Rectangle {
		id: border_left;
		anchors.top: top_side.bottom;
		anchors.left: parent.left;
		anchors.bottom: parent.bottom;
		width: Math.round(2 * _ratio);
		color: border_color;
	}

	Rectangle {
		id: border_right;
		anchors.top: top_side.bottom;
		anchors.right: parent.right;
		anchors.bottom: parent.bottom;
		width: Math.round(2 * _ratio);
		color: border_color;
	}

	Rectangle {
		id: border_bottom;
		anchors.left: border_left.right;
		anchors.right: border_right.left;
		anchors.bottom: parent.bottom;
		height: Math.round(2 * _ratio);
		color: border_color;
	}

	Rectangle {
		id: border_top;
		anchors.left: border_left.right;
		anchors.right: border_right.left;
		anchors.top: navigation_bar.bottom;
		height: Math.round(2 * _ratio);
		color: border_color;
	}

	Item {
		id: navigation_bar;
		anchors.left: border_left.right;
		anchors.right: border_right.left;
		anchors.top: top_side.bottom;
		height: Math.round(36 * _ratio);
	}

	Item {
		id: bottom_side;
		anchors.left: border_left.right;
		anchors.top: navigation_bar.bottom;
		anchors.right: border_right.left;
		anchors.bottom: border_bottom.top;
	}

	Component {
		id: about_menu;

		MenuLightning { }
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

	//		WebEngineView {
	//			anchors.fill: parent;
	//			anchors.topMargin: 50;

	//			url: "http://disk.yandex.ru";

	//			settings.autoLoadImages: false;
	//			settings.javascriptCanOpenWindows: false;
	//			profile.persistentCookiesPolicy: WebEngineProfile.NoPersistentCookies;

	//			onTitleChanged: console.log("Title changed:" + title);

	//			onIconChanged: console.log(icon);
	//			Component.onCompleted: console.log(icon);
	//		}
}
