#include "internalchange.h"

#include "../private/cursor.h"
#include "../private/selection.h"
#include "../self/logic.h"

namespace icL::editor {

InternalChange::InternalChange() = default;

ChangeEntity::ChangeEntity(int line, int column, bool isMain)
	: line(line)
	, column(column)
	, isMain(isMain) {}

InternalChange::~InternalChange() {
	for (auto * ptr : changes) {
		delete ptr;
	}
}

bool InternalChange::hasInsert() {
	return m_hasInsert;
}

void InternalChange::markInsert() {
	m_hasInsert = true;
}

ChangeEntity * InternalChange::addChange(int line, int column, bool isMain) {
	ChangeEntity * ret = nullptr;

	// Switch to true if you have found a cursor in nedded line
	bool cursorAtLineFound = false;

	for (auto * droppedChange : droppedChanges) {
		if (droppedChange->line == line) {
			int currentColumn = droppedChange->column -
								droppedChange->stepBack +
								droppedChange->inserted.length();

			if (currentColumn == column) {
				ret = droppedChange;

				droppedChanges.removeOne(ret);
				changes.append(ret);
			}

			cursorAtLineFound = true;
			break;
		}
	}

	if (ret == nullptr && !cursorAtLineFound) {
		ret = new ChangeEntity(line, column, isMain);
	}

	return ret;
}

void InternalChange::dropChange(int line, int column) {
	for (auto * change : changes) {

		if (change->line == line) {
			int currentColumn =
			  change->column - change->stepBack + change->inserted.length();

			if (currentColumn == column) {
				changes.removeOne(change);
				droppedChanges.append(change);
			}
		}
	}
}

void InternalChange::undo(Logic * logic) {
	logic->lSyncSelectionsWith(this);

	auto * itSelection = logic->hGetFirstSelection();
	auto   itChange    = changes.begin();

	while (itSelection != nullptr) {
		itSelection->begin()->matchPreffered();
		itSelection->end()->syncWith(itSelection->begin());

		itSelection->move((*itChange)->inserted.length(), true);
		itSelection->rawDrop();
		itSelection->rawInsert((*itChange)->deleted);

		itSelection = itSelection->next();
		itChange++;
	}
}

const QLinkedList<ChangeEntity *> InternalChange::getChanges() {
	return changes;
}

void InternalChange::redo(Logic * logic) {
	logic->lSyncSelectionsWith(this);

	auto * itSelection = logic->hGetLastSelection();
	auto   itChange    = changes.end();

	while (itSelection != nullptr) {
		itSelection->move((*itChange)->deleted.length(), true);
		itSelection->rawDrop();
		itSelection->rawInsert((*itChange)->inserted);

		itSelection = itSelection->prev();
		itChange--;
	}
}

}  // namespace icL::editor
