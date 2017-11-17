import QtQuick 2.5

import "../../ui/controls/speed_dial" as SpeedDialControls;

ContentBase {
	id: root;

	Item {
		id: dial;
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
	}
}
