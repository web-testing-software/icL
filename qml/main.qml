import QtQuick 2.7
import QtWebEngine 1.5
import QtQuick.Window 2.3
import QtGraphicalEffects 1.0

import "components/browser";
import "components/browser/contextmenu";

import "scripts/move_flags.js" as MOVE_FLAGS;

Item {
	id: win;

	property string app_version: "1.0.0 dev";
	property real _ratio: Math.max(Screen.pixelDensity, 5.5) / 5.5;
	property real anim_time_multiplier: 1;


	property color focus_color: "#003bc5";
	property real focus_hue: 0.62;

	property color border_color: "#20232323";

	property var current_webview: null;

	function paste_menu (component, properties, x, y) {
		var menu = component.createObject(pastemenu, properties);
		pastemenu.menus.push(menu);
		pastemenu.visible = true;
		menu.show (x, y);
	}

	Rectangle {
		id: win_rectangle;
		color: web_browser.isFocused ? "#eef5f5f5" : "#a0e1e1e2";

		anchors.fill: parent;
		anchors.margins: web_browser.isMaximized ? 0 : Math.round(4 * _ratio);

		Behavior on color {
			ColorAnimation {
				duration: 200 * anim_time_multiplier;
			}
		}

		ResizeMoveMouseArea {
			id: top_side;
			anchors.top: parent.top;
			anchors.left: parent.left;
			anchors.right: parent.right;
			height: Math.round(44 * _ratio);

			cursorShape: Qt.SizeAllCursor;
			flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.V_MOVE;

			Rectangle {
				anchors.left: parent.left;
				anchors.right: parent.right;
				anchors.bottom: parent.bottom;
				height: Math.round(2 * _ratio);
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
				anchors.right: title_bar_buttons.left;
				anchors.bottom: parent.bottom;
				anchors.leftMargin: Math.round(4 * _ratio);
				anchors.rightMargin: Math.round(4 * _ratio);

				property variant current_tab: test_tab;

				Item  {
					x: top_tab_bar.current_tab.x;
					width: top_tab_bar.current_tab.width;
					height: Math.round(36 * _ratio);
					anchors.bottom: parent.bottom;

					Rectangle {
						anchors.fill: parent;
						anchors.margins: Math.round(2 * _ratio);
						anchors.bottomMargin: 0;
					}

					Rectangle {
						id: tb;
						anchors.top: parent.top;
						anchors.left: parent.left;
						anchors.right: parent.right;
						color: border_color;
						height: Math.round(2 * _ratio);
					}

					Rectangle {
						id: lb;
						anchors.top: tb.bottom;
						anchors.left: parent.left;
						anchors.bottom: parent.bottom;
						color: border_color;
						width: Math.round(2 * _ratio);
					}

					Rectangle {
						id: rb;
						anchors.top: tb.bottom;
						anchors.right: parent.right;
						anchors.bottom: parent.bottom;
						color: border_color;
						width: Math.round(2 * _ratio);
					}
				}

				Row {
					id: tab_container;
					height: Math.round(34 * _ratio);
					anchors.left: parent.left;
					anchors.bottom: parent.bottom;

					property int max_tab_width: Math.round(300 * _ratio);
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
					width: Math.round(34 * _ratio);
					height: Math.round(34 * _ratio);

					anchors.left: tab_container.right;
					anchors.bottom: parent.bottom;

					Image {
						id: new_tab;
						source: "qrc:/images/new_tab.svg";
						sourceSize: Qt.size(Math.round(14 * _ratio), Math.round(14 * _ratio));
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

			Row {
				id: title_bar_buttons;
				anchors.right: parent.right;
				anchors.top: parent.top;
				anchors.margins: Math.round(2 * _ratio);

				TitleBarButton {
					icon: "qrc:/images/minimize_button.svg";

					function click () {
						web_browser.showMinimized();
					}
				}

				TitleBarButton {
					icon: "qrc:/images/maximize_button.svg";

					function click () {
						if (web_browser.isMaximized) {
							web_browser.showNormal();
						}
						else {
							web_browser.showMaximized();
						}
					}
				}

				TitleBarButton {
					icon: "qrc:/images/close_button.svg";

					function click () {
						web_browser.close();
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
			anchors.top: navigation_bar_container.bottom;
			height: Math.round(2 * _ratio);
			color: border_color;
		}

		Rectangle {
			id: navigation_bar_container;
			anchors.left: border_left.right;
			anchors.right: border_right.left;
			anchors.top: top_side.bottom;
			height: Math.round(36 * _ratio);
			color: "white";

			NavigationBar {
				id: navigation_bar;
			}
		}

		Item {
			id: bottom_side;
			anchors.left: border_left.right;
			anchors.top: navigation_bar_container.bottom;
			anchors.right: border_right.left;
			anchors.bottom: border_bottom.top;
		}

		Item {
			anchors.left: border_left.right;
			anchors.right: border_right.left;
			anchors.top: border_top.bottom;
			anchors.bottom: border_bottom.top;

			WebEngineView {
				id: wview;
				anchors.fill: parent;
				//			anchors.topMargin: 50;

				url: "https://gitlab.com/lixcode/ic-lightning";

				settings.autoLoadImages: false;
				settings.javascriptCanOpenWindows: false;
				profile.persistentCookiesPolicy: WebEngineProfile.NoPersistentCookies;

				onTitleChanged: console.log("Title changed:" + title);

				onIconChanged: console.log(icon);
				Component.onCompleted: console.log(icon);
			}
		}

		Component {
			id: about_menu;

			MenuLightning { }
		}

		MouseArea {
			id: pastemenu;
			anchors.fill: parent;
			visible: false;
			hoverEnabled: true;

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
	}

	DropShadow {
		visible: !web_browser.isMaximized;
		anchors.fill: parent;
		anchors.margins: win_rectangle.anchors.margins;
		radius: anchors.margins;
		color: "#80000000";
		source: win_rectangle;
		horizontalOffset: 0;
		verticalOffset: 0;
	}

	property int resize_border_weight: Math.round(6 * _ratio);
	property int resize_angle_weight: Math.round(12 * _ratio);

	ResizeMoveMouseArea {
		id: rsz_tll;
		visible: !web_browser.isMaximized;
		anchors.left: parent.left;
		anchors.top: parent.top;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_tlt;
		visible: !web_browser.isMaximized;
		anchors.left: rsz_tll.right;
		anchors.top: parent.top;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_t;
		visible: !web_browser.isMaximized;
		anchors.left: rsz_tlt.right;
		anchors.right: rsz_trt.left;
		anchors.top: parent.top;
		height: resize_border_weight;
		cursorShape: Qt.SizeVerCursor;
		flag: MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_trt;
		visible: !web_browser.isMaximized;
		anchors.top: parent.top;
		anchors.right: rsz_trr.left;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_trr;
		visible: !web_browser.isMaximized;
		anchors.top: parent.top;
		anchors.right: parent.right;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_r;
		visible: !web_browser.isMaximized;
		anchors.top: rsz_trr.bottom;
		anchors.bottom: rsz_brr.top;
		anchors.right: parent.right;
		width: resize_border_weight;
		cursorShape: Qt.SizeHorCursor;
		flag: MOVE_FLAGS.H_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_brr;
		visible: !web_browser.isMaximized;
		anchors.right: parent.right;
		anchors.bottom: parent.bottom;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_brb;
		visible: !web_browser.isMaximized;
		anchors.right: rsz_brr.left;
		anchors.bottom: parent.bottom;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_b;
		visible: !web_browser.isMaximized;
		anchors.left: rsz_blb.right;
		anchors.right: rsz_brb.left;
		anchors.bottom: parent.bottom;
		height: resize_angle_weight;
		cursorShape: Qt.SizeVerCursor;
		flag: MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_blb;
		visible: !web_browser.isMaximized;
		anchors.left: rsz_bll.right;
		anchors.bottom: parent.bottom;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_bll;
		visible: !web_browser.isMaximized;
		anchors.left: parent.left;
		anchors.bottom: parent.bottom;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	ResizeMoveMouseArea {
		id: rsz_l;
		visible: !web_browser.isMaximized;
		anchors.top: rsz_tll.bottom;
		anchors.bottom: rsz_bll.top;
		anchors.left: parent.left;
		width: resize_border_weight;
		cursorShape: Qt.SizeHorCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE;
	}
}
