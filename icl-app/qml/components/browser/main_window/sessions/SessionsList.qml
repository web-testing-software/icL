import QtQuick 2.0

Item {
	id: root;
	anchors.fill: parent;

	property int ith: 0;
	property SessionBase current_session: select_screen;

	property bool manage_mode: false;

	Component {
		id: session_delegate;

//		WebSession {
//			//
//		}

		ScriptSession { }
	}

	SelectScreen {
		id: select_screen;
		z: 1;
	}

	function updateStateForItems () {
		current_session.updateState();
		if (!!current_session.prev) {
			current_session.prev.updateState();
		}
		if (!!current_session.next) {
			current_session.next.updateState();
			if (!!current_session.next.next) {
				current_session.next.next.updateState();
				if (!!current_session.next.next.next) {
					current_session.next.next.next.updateState();
				}
			}
		}
	}

	onCurrent_sessionChanged: updateStateForItems();
	onManage_modeChanged: updateStateForItems();

	function to_prev () {
		if (!!current_session.prev) {
			current_session.shown = false;
			current_session = current_session.prev;
		}
	}

	function to_next () {
		if (!!current_session.next) {
			if (manage_mode && !current_session.next.next) {
				return;
			}

			current_session = current_session.next;
			current_session.shown = true;
		}
	}

	function fix_z_index () {
		var it = current_session;

		if (!!current_session.prev) {
			it.z = current_session.prev.z >= 999 ? 2 : current_session.prev.z + 1;
		}
		else {
			current_session.z = 1;
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
		current_session = obj;

		fix_z_index();

		manage_mode = false;
		if (select_screen.z > 0) {
			select_screen.hide();
		}

		global_focus_scope.forceActiveFocus();
	}

	function enter_manage_mode () {

		current_session.set_manage_mode();

		var it = current_session.prev;

		while (!!it) {
			it.set_manage_mode();
			it = it.prev;
		}

		it = current_session.next;

		while (!!it) {
			it.set_manage_mode();
			it = it.next;
		}

		manage_mode = true;
		to_prev();
		updateStateForItems();

		if (select_screen.z > 1) {
			select_screen.hide();
		}

		forceActiveFocus();
	}

	function exit_manage_mode (steps) {
		manage_mode = false;

		for (var i = 0; i < steps; i++) {
			to_next();
		}
	}

	Component.onCompleted: {
//		add_new_session();
		add_new_session();
//		add_new_session();
//		add_new_session();
	}
}
