import QtQuick 2.0
import QtGraphicalEffects 1.0

import "../content";
import "../header";

SessionBase {
	id: root;

	Rectangle {
		id: top_side;
		anchors.top: parent.top;
		anchors.left: parent.left;
		anchors.right: parent.right;
		height: Math.round(web_browser.isMaximized ? 40 : 44 * _ratio);		

		color: web_browser.isFocused && sessions_list.current_item == root ? "#f5f5f5" : "#e1e1e2";

		Behavior on color {
			ColorAnimation {
				duration: 200 * anim_time_multiplier;
			}
		}

		Rectangle {
			anchors.left: parent.left;
			anchors.right: parent.right;
			anchors.bottom: parent.bottom;
			height: Math.round(2 * _ratio);
			color: border_color;
		}

		Item {
			id: top_tab_bar;
			anchors.left: parent.left;
			anchors.top: parent.top;
			anchors.right: parent.right;
			anchors.rightMargin: title_bar_buttons.width + Math.round(4 * _ratio);
			anchors.bottom: parent.bottom;
			anchors.leftMargin: logo.width + Math.round(4 * _ratio);

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
		id: content;
		anchors.left: border_left.right;
		anchors.right: border_right.left;
		anchors.top: border_top.bottom;
		anchors.bottom: border_bottom.top;

		Item {
			id: paste_tabview;

			anchors.fill: parent;

			EditorTabContent {
			}
		}
	}
}
