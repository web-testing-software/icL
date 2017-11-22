import QtQuick 2.5

import "../../ui/controls/speed_dial" as SpeedDialControls;

ContentBase {
	id: root;

	Item {
		id: dial_container;
		width: Math.round(848 * _ratio);
		height: Math.round(558 * _ratio);
		anchors.centerIn: parent;

		Item {
			id: header;
			anchors.top: parent.top;
			anchors.left: parent.left;
			anchors.right: parent.right;
			height: Math.round(40 * _ratio);

			SpeedDialControls.New {
				id: new_button;
			}

			SpeedDialControls.Open {
				id: open_button;

				anchors.left: new_button.right;
			}

			SpeedDialControls.Search {
				id: search_area;
				anchors.left: open_button.right;
				anchors.right: parent.right;
			}
		}

		Grid {
			anchors.top: header.bottom;
			anchors.topMargin: Math.round(30 * _ratio);
			anchors.left: parent.left;
			anchors.right: parent.right;
			anchors.bottom: parent.bottom;

			columns: 3;
			columnSpacing: Math.round(40 * _ratio);
			rowSpacing: Math.round(30 * _ratio);

			Repeater {
				id: dials;
				model: 9;

				SpeedDialControls.DialBase {
					//
				}
			}
		}
	}
}
