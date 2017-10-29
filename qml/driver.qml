import QtQuick 2.7
import QtQuick.Window 2.3
import QtGraphicalEffects 1.0

import "components/browser/main_window";
import "components/browser/contextmenu";
import "components/browser/ui/controls";

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
		color: web_browser.isFocused ? "#f5f5f5" : "#e1e1e2";
		layer.enabled: true;

		anchors.fill: parent;
		anchors.margins: web_browser.isMaximized ? 0 : Math.round(4 * _ratio);

		Behavior on color {
			ColorAnimation {
				duration: 200 * anim_time_multiplier;
			}
		}

		ResizeMoveMouseArea {
			id: move_area;

			clip: true;
			anchors.fill: parent;
			flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.V_MOVE;

			property bool sessions_manage_mode: false;

			Rectangle {
				id: sessions_manager;
				visible: opacity != 0.0;
				opacity: 1.0;

				anchors.fill: parent;
				color: "#ffffff";

				state: move_area.sessions_manage_mode ? "" : "hidden";

				states: [
					State {
						name: "hidden";
						PropertyChanges {
							target: sessions_manager;
							opacity: 0.0;
						}
					}
				]

				transitions: [
					Transition {
						from: "hidden";
						to: "*";
						NumberAnimation {
							property: "opacity";
							duration: 250 * anim_time_multiplier;
						}
					}
				]

				property real button_space: Math.round(50 * _ratio);

				Item {
					anchors.top: parent.top;
					anchors.right: parent.right;
					anchors.left: parent.left;
					height: window_list.vertical_white_space;

					Button {
						pixelSize: Math.round(20 * _ratio);
						anchors.centerIn: parent;

						text: qsTr("Add new session before the current");

						onClicked: select_screen.show("top");
					}
				}

				Item {
					anchors.top: parent.top;
					anchors.right: parent.right;
					anchors.bottom: parent.bottom;
					width: window_list.horizontal_white_space;

					Button {
						pixelSize: Math.round(20 * _ratio);
						anchors.centerIn: parent;

						text: qsTr("Remove session");
						rotation: 270;

						onClicked: select_screen.show("add_after");
					}
				}

				Item {
					anchors.right: parent.right;
					anchors.bottom: parent.bottom;
					anchors.left: parent.left;
					height: window_list.vertical_white_space;

					Button {
						pixelSize: Math.round(20 * _ratio);
						anchors.centerIn: parent;

						text: qsTr("Add new session after the current");

						onClicked: select_screen.show("bottom");
					}
				}

				Item {
					anchors.top: parent.top;
					anchors.bottom: parent.bottom;
					anchors.left: parent.left;
					width: window_list.horizontal_white_space;

					Button {
						pixelSize: Math.round(20 * _ratio);
						anchors.centerIn: parent;

						text: qsTr("Clear session");
						rotation: 90;

						onClicked: select_screen.show("add_before");
					}
				}
			}

			WindowContent {
				id: window_list;
				scale: 1.0;

				state: move_area.sessions_manage_mode ? "micro" : "";

				states: [
					State {
						name: "micro"
						PropertyChanges {
							target: window_list
							scale: preffered_scale;
						}
					}
				]

				transitions: Transition {
					from: "*"
					to: "micro"
					NumberAnimation {
						property: "scale";
						duration: 250 * anim_time_multiplier;
					}
				}

				property real preffered_scale: Math.min((width - 100 * _ratio) / width, (height - 100 * _ratio) / height);
				property real horizontal_white_space: 0.5 * width * (1 - preffered_scale);
				property real vertical_white_space: 0.5 * height * (1 - preffered_scale);
			}

			Timer {
				interval: 2000;
				running: true;
				repeat: true;
				onTriggered: move_area.sessions_manage_mode = !move_area.sessions_manage_mode;
			}

			SelectScreen {
				id: select_screen;
				state: "hide";
				visible: opacity != 0.0 && scale != 0.0;
			}

			Toast {
				id: top_toast;
				is_bottom: false;
				beginY: -Math.round(50 * _ratio);
				endY: 0;
			}

			Toast {
				id: bottom_toast;
				is_bottom: true;
				beginY: parent.height;
				endY: parent.height - Math.round(50 * _ratio);
			}

		}

		Logo {
			id: logo;
			onClicked: paste_menu(about_menu, {y: y - Math.round(2 * _ratio)}, mouseX, mouseY);
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
