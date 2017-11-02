import QtQuick 2.0

Item {
	id: root;
	anchors.fill: parent;

//	clip: true;
//	scale: 1.0;
//	state: active_area.sessions_manage_mode ? "micro" : active_area.cancel_session ? "canceled" : "";

	property real preffered_scale: Math.min((width - 100 * _ratio) / width, (height - 100 * _ratio) / height);
	property real horizontal_white_space: 0.5 * width * (1 - preffered_scale);
	property real vertical_white_space: 0.5 * height * (1 - preffered_scale);

	property int current_index: 0;
	property SessionBase current_item: null;

	Component {
		id: session_delegate;

		WebSession {
			//
		}
	}

	states: [
		State {
			name: "micro";
			PropertyChanges {
				target: sessions_list;
				scale: preffered_scale;
			}
		},
		State {
			name: "canceled";
			PropertyChanges {
				target: sessions_list;
				scale: 1;
			}
		}
	]

	transitions: Transition {
		from: "*";
		to: "micro,canceled";
		NumberAnimation {
			property: "scale";
			duration: 250 * anim_time_multiplier;
		}
	}

	function to_prev () {
		if (!!current_item.prev) {
			current_item.prev.visible = true;
			current_item.shown = false;
			current_item = current_item.prev;
		}
	}

	function to_next () {
		if (!!current_item.next) {
			current_item.next.visible = true;
			current_item = current_item.next;
			current_item.shown = true;

			if (active_area.sessions_manage_mode
					&& !!current_item.next
					&& !!current_item.next.next) {
				current_item.next.next.visible = true;
			}
		}
	}

	function fix_z_index () {
		var it = current_item.prev;

		if (current_item.prev) {
			it = current_item.prev
		}
		else {
			current_item.z = 0;
			it = current_item;
		}

		while (!!it.next) {
			it.next.z = it.z + 1;
			it = it.next;
		}
	}

	function add_new_session () {
		var obj = session_delegate.createObject(root, {});

		if (current_item == null) {
			current_item = obj;
			current_index = 0;
			current_item.z = 1;
		}
		else if (select_screen.add_after_current) {
			if (!!current_item.next) {
				current_item.next.prev = obj;
			}
			obj.prev = current_item;
			obj.next = current_item.next;
			current_item.next = obj;
			current_item = obj;

			fix_z_index();
		}
		else {
			current_index.shown = false;

			if (!!current_item.prev) {
				current_item.prev.next = obj;
			}
			obj.next = current_item;
			obj.prev = current_item.prev;
			current_item.prev = obj;
			current_item = obj;

			fix_z_index();
		}

		active_area.cancel_session = false;
		active_area.sessions_manage_mode = false;

		select_screen.hide();

		active_area.forceActiveFocus();
	}

	Component.onCompleted: {
		add_new_session();
		add_new_session();
		add_new_session();
		add_new_session();
	}
}
