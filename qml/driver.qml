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

Item {
	id: win;

	property string app_version: "1.0.0 dev";
	property real _ratio: Math.max(Screen.pixelDensity, 5.5) / 5.5;
	property real anim_time_multiplier: 1;


	property color focus_color: "#003bc5";
	property real focus_hue: 0.62;

    property color border_color: "#cecece";

	property var current_webview: null;

	function paste_menu (component, properties, x, y) {
		var menu = component.createObject(pastemenu, properties);
		pastemenu.menus.push(menu);
		pastemenu.visible = true;
		menu.show (x, y);
	}

	Item {
		id: win_rectangle;
		layer.enabled: true;

		anchors.fill: parent;
		anchors.margins: web_browser.isMaximized ? 0 : Math.round(4 * _ratio);

		MainWindow.ResizeMoveMouseArea {
			id: active_area;

			clip: true;
			anchors.fill: parent;
			flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.V_MOVE;

			property bool sessions_manage_mode: false;
			property bool cancel_session: false;

			Keys.onTabPressed: {
				if (event.modifiers & Qt.ControlModifier && !sessions_manage_mode) {
					cancel_session = false;

					sessions_list.to_prev();
					sessions_manage_mode = true;
					sessions_list.forceActiveFocus();
				}
			}

			Keys.onEscapePressed: {
				if (sessions_manage_mode == true) {

					cancel_session = true;
					sessions_manage_mode = false;

					sessions_list.to_next();
				}
			}

			Keys.onUpPressed: {
				if (sessions_manage_mode == true
						|| (event.modifiers == (Qt.ControlModifier | Qt.ShiftModifier))) {
					sessions_list.to_prev();
				}
			}

			Keys.onDownPressed: {
				if (sessions_manage_mode == true
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
				visible: active_area.sessions_manage_mode;
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

		Header.Logo {
			id: logo;
			onClicked: paste_menu(about_menu, {y: y - Math.round(2 * _ratio)}, mouseX, mouseY);
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
		visible: !web_browser.isMaximized;
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
		visible: !web_browser.isMaximized;
		anchors.left: parent.left;
		anchors.top: parent.top;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_tlt;
		visible: !web_browser.isMaximized;
		anchors.left: rsz_tll.right;
		anchors.top: parent.top;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_t;
		visible: !web_browser.isMaximized;
		anchors.left: rsz_tlt.right;
		anchors.right: rsz_trt.left;
		anchors.top: parent.top;
		height: resize_border_weight;
		cursorShape: Qt.SizeVerCursor;
		flag: MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_trt;
		visible: !web_browser.isMaximized;
		anchors.top: parent.top;
		anchors.right: rsz_trr.left;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_trr;
		visible: !web_browser.isMaximized;
		anchors.top: parent.top;
		anchors.right: parent.right;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_MOVE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_r;
		visible: !web_browser.isMaximized;
		anchors.top: rsz_trr.bottom;
		anchors.bottom: rsz_brr.top;
		anchors.right: parent.right;
		width: resize_border_weight;
		cursorShape: Qt.SizeHorCursor;
		flag: MOVE_FLAGS.H_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_brr;
		visible: !web_browser.isMaximized;
		anchors.right: parent.right;
		anchors.bottom: parent.bottom;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_brb;
		visible: !web_browser.isMaximized;
		anchors.right: rsz_brr.left;
		anchors.bottom: parent.bottom;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeFDiagCursor;
		flag: MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_b;
		visible: !web_browser.isMaximized;
		anchors.left: rsz_blb.right;
		anchors.right: rsz_brb.left;
		anchors.bottom: parent.bottom;
		height: resize_angle_weight;
		cursorShape: Qt.SizeVerCursor;
		flag: MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_blb;
		visible: !web_browser.isMaximized;
		anchors.left: rsz_bll.right;
		anchors.bottom: parent.bottom;
		width: resize_angle_weight;
		height: resize_border_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_bll;
		visible: !web_browser.isMaximized;
		anchors.left: parent.left;
		anchors.bottom: parent.bottom;
		width: resize_border_weight;
		height: resize_angle_weight;
		cursorShape: Qt.SizeBDiagCursor;
		flag: MOVE_FLAGS.H_MOVE | MOVE_FLAGS.H_RESIZE | MOVE_FLAGS.V_RESIZE;
	}

	MainWindow.ResizeMoveMouseArea {
		id: rsz_l;
		visible: !web_browser.isMaximized;
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

		property bool was_maximised: false;
		property real last_location: 0;
		property real last_width: 0;
		property point global_pos;
		property int flag;

		onTriggered: {
			var alpha = 0.0;
			if (was_maximised) {
				alpha = last_location > last_width - width / 2
						? 1 - (last_width - last_location) / width
						: last_location < width / 2
						  ? last_location / width
						  : 0.5;
			}
			web_browser.beginWindowMove(global_pos.x, global_pos.y, flag, was_maximised, alpha);
		}
	}
}
