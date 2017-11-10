import QtQuick 2.0

Item {
	id: root;
	anchors.fill: parent;

	property int ith: 0;
	property SessionBase current_item: select_screen;

	property bool manage_mode: false;

	Component {
		id: session_delegate;

		WebSession {
			//
		}
	}

	SelectScreen {
		id: select_screen;
		z: 1;
	}

	function updateStateForItems () {
		current_item.updateState();
		if (!!current_item.prev) {
			current_item.prev.updateState();
//			if (!!current_item.prev.prev) {
//				current_item.prev.prev.updateState();
//			}
		}
		if (!!current_item.next) {
			current_item.next.updateState();
			if (!!current_item.next.next) {
				current_item.next.next.updateState();
				if (!!current_item.next.next.next) {
					current_item.next.next.next.updateState();
				}
			}
		}
	}

	onCurrent_itemChanged: updateStateForItems();
	onManage_modeChanged: updateStateForItems();

	function to_prev () {
		if (!!current_item.prev) {
			current_item.shown = false;
			current_item = current_item.prev;
		}
	}

	function to_next () {
		if (!!current_item.next) {
			if (manage_mode && !current_item.next.next) {
				return;
			}

			current_item = current_item.next;
			current_item.shown = true;
		}
	}

	function fix_z_index () {
		var it = current_item;

		if (!!current_item.prev) {
			it.z = current_item.prev.z >= 999 ? 2 : current_item.prev.z + 1;
		}
		else {
			current_item.z = 1;
		}

		while (!!it.next) {
			it.next.z = it.z + 1;
			it = it.next;
		}
	}

	function add_new_session () {
		var obj = session_delegate.createObject(root, {});

		var after = select_screen.add_after;

		if (!!after.next) {
			after.next.prev = obj;
		}
		obj.prev = after;
		obj.next = after.next;
		after.next = obj;
		obj.ith = ++ith;
		after.shown = true;
		if (!!after.prev) after.prev.shown = true;
		current_item = obj;

		fix_z_index();

		manage_mode = false;
		if (select_screen.z > 0) {
			select_screen.hide();
		}

		active_area.forceActiveFocus();
	}

	function enter_manage_mode () {
		to_prev();

		if (select_screen.z > 1) {
			select_screen.hide();
		}

		manage_mode = true;
		forceActiveFocus();
	}

	function exit_manage_mode (steps) {
		manage_mode = false;

		for (var i = 0; i < steps; i++) {
			to_next();
		}
	}

//	Component.onCompleted: {
//		add_new_session();
//		add_new_session();
//		add_new_session();
//		add_new_session();
//	}
}
