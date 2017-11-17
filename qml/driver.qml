import QtQuick 2.5
import QtQuick.Window 2.1
import QtGraphicalEffects 1.0

import "components/browser/main_window" as MainWindow;
import "components/browser/main_window/content" as Content;
import "components/browser/main_window/header" as Header;
import "components/browser/main_window/header/title_bar_buttons" as TitleBarButtons;
import "components/browser/main_window/sessions" as Sessions;
import "components/browser/contextmenu" as ContextMenu;
import "components/browser/ui/controls" as Controls;

import "scripts/my_enums.js" as ME;
import "scripts/move_flags.js" as MOVE_FLAGS;

Window {
	id: win;

	width: 1000;
	height: 700;
	visible: true;
	flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowSystemMenuHint;

	minimumWidth: Math.round(1000 * _ratio);
	minimumHeight: Math.round(700 * _ratio);

	property string app_version: "1.0.0 dev";
	property real _ratio: Math.max(Screen.pixelDensity, 4.5) / 5.5;
	property real anim_time_multiplier: 1;


	property color focus_color: "#003bc5";
	property real focus_hue: 0.62;

	property color border_color: "#cecece";

	color: "transparent";

	property bool isMaximized: visibility == Window.Maximized;
	property var current_webview: null;

	function paste_menu (component, properties, x, y) {
		var menu = component.createObject(pastemenu, properties);
		pastemenu.menus.push(menu);
		pastemenu.visible = true;
		menu.show (x, y);
	}

	MainWindow.MouseField {
		id: win_rectangle;
		layer.enabled: true;

		anchors.fill: parent;
		anchors.margins: win.isMaximized ? 0 : Math.round(4 * _ratio);

		clip: true;

		FocusScope {
			id: global_focus_scope;

			focus: true;
			anchors.fill: parent;

			Keys.onTabPressed: {
				if (event.modifiers & Qt.ControlModifier && !sessions_list.manage_mode) {
					sessions_list.enter_manage_mode();
				}
			}

			Keys.onEscapePressed: {
				if (sessions_list.manage_mode == true) {
					sessions_list.exit_manage_mode(1);
				}
			}

			Keys.onUpPressed: {
				if (sessions_list.manage_mode == true
						|| (event.modifiers == (Qt.ControlModifier | Qt.ShiftModifier))) {
					sessions_list.to_prev();
				}
			}

			Keys.onDownPressed: {
				if (sessions_list.manage_mode == true
						|| (event.modifiers == (Qt.ControlModifier | Qt.ShiftModifier))) {
					sessions_list.to_next();

					event.accepted = true;
				}
				else {
					console.log(Qt.ControlModifier | Qt.ShiftModifier, event.modifiers);
				}
			}

			Sessions.SessionsList {
				id: sessions_list;
			}

			// In the session manage mode the bottom border is not always visible
			Rectangle {
				visible: sessions_list.manage_mode;
				anchors.left: parent.left;
				anchors.right: parent.right;
				anchors.bottom: parent.bottom;

				height: Math.round(2 * _ratio);
				color: border_color;
			}

			Sessions.Toast {
				id: top_toast;
				is_bottom: false;
				beginY: -Math.round(50 * _ratio);
				endY: 0;
			}

			Sessions.Toast {
				id: bottom_toast;
				is_bottom: true;
				beginY: parent.height;
				endY: parent.height - Math.round(50 * _ratio);
			}

		}

		TitleBarButtons.BackLightningMenu {
			id: logo;
			onClicked: paste_menu(about_menu, {y: y - Math.round(2 * _ratio)}, mouseX, mouseY);

			need_back: sessions_list.manage_mode;
		}

		Row {
			id: title_bar_buttons;
			anchors.right: parent.right;
			anchors.top: parent.top;
			anchors.margins: Math.round(6 * _ratio);
			spacing: Math.round(4 * _ratio);

			TitleBarButtons.Minimize {
				//
			}

			TitleBarButtons.Maximize {
				//
			}

			TitleBarButtons.Close {
				//
			}
		}

		Component {
			id: about_menu;

			ContextMenu.MenuLightning { }
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
		visible: !win.isMaximized;
		anchors.fill: win_rectangle;
		radius: win_rectangle.anchors.margins;
		color: "#80000000";
		source: win_rectangle;
		horizontalOffset: 0;
		verticalOffset: 0;
		cached: true;
	}


	property int resize_border_weight: Math.round(6 * _ratio);
	property int resize_angle_weight: Math.round(12 * _ratio);

	MainWindow.ResizeMoveMouseArea {
		id: rsz_tll;
		visible: !win.isMaximized;
		anchors.left: parent.left;
		anchors.top: parent.top;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_tlt;
		visible: !win.isMaximized;
		anchors.left: rsz_tll.right;
		anchors.top: parent.top;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_t;
		visible: !win.isMaximized;
		anchors.left: rsz_tlt.right;
		anchors.right: rsz_trt.left;
		anchors.top: parent.top;
		height: resize_border_weight;
		cursorShape: Qt.SizeVerCursor;
		flag: MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_trt;
		visible: !win.isMaximized;
		anchors.top: parent.top;
		anchors.right: rsz_trr.left;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_trr;
		visible: !win.isMaximized;
		anchors.top: parent.top;
		anchors.right: parent.right;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_r;
		visible: !win.isMaximized;
		anchors.top: rsz_trr.bottom;
		anchors.bottom: rsz_brr.top;
		anchors.right: parent.right;
		width: resize_border_weight;
		cursorShape: Qt.SizeHorCursor;
		flag: MOVE_FLAGS.H_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_brr;
		visible: !win.isMaximized;
		anchors.right: parent.right;
		anchors.bottom: parent.bottom;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_brb;
		visible: !win.isMaximized;
		anchors.right: rsz_brr.left;
		anchors.bottom: parent.bottom;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_b;
		visible: !win.isMaximized;
		anchors.left: rsz_blb.right;
		anchors.right: rsz_brb.left;
		anchors.bottom: parent.bottom;
		height: resize_angle_weight;
		cursorShape: Qt.SizeVerCursor;
		flag: MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_blb;
		visible: !win.isMaximized;
		anchors.left: rsz_bll.right;
		anchors.bottom: parent.bottom;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_bll;
		visible: !win.isMaximized;
		anchors.left: parent.left;
		anchors.bottom: parent.bottom;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_l;
		visible: !win.isMaximized;
		anchors.top: rsz_tll.bottom;
		anchors.bottom: rsz_bll.top;
		anchors.left: parent.left;
		width: resize_border_weight;
		cursorShape: Qt.SizeHorCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE;
	}

	// This timer fix bug for maximised window
	Timer {
		id: resize_move_timer;
		interval: 10;

		property var resize_move_area;

		onTriggered: resize_move_area.pressedDelayFunction();
	}
}
