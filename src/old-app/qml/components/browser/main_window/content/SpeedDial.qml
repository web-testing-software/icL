import QtQuick 2.5

import icL.DB 1.0

import "../../ui/controls/speed_dial" as SpeedDialControls;

ContentBase {
	id: root;

	property string cache_dir: helper.cacheDir(profile_name + "/speed_dial/");

	property var requests: [];
	property int current_index: -1;
	property var browser_obj: null;

	function update_dial_icon (path, url) {
		requests.push({path: path, url: url});

		if (!browser_obj) {
			browser_obj = browser_component.createObject(root);
		}
	}

	function request_update_thumbnails () {
		for (var i = 0; i < 9; i++) {
			if (!dials.itemAt(i).is_ok) {
				dials.itemAt(i).update_dial_thumbnail();
				break;
			}
		}
	}

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

			Component.onCompleted: {
				var descriptions = database.top9();

				for (var i = 0; i < descriptions.length; i++) {
					var dial = dials.itemAt(i);

					if (!!dial.description) {
						delete dial.description;
					}

					dial.description = descriptions[i];
				}

				for (i = descriptions.length; i < 9; i++) {
					var dial = dials.itemAt(i);

					if (!!dial.description) {
						delete dial.description;
					}

					dial.description = null;
				}
			}

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
