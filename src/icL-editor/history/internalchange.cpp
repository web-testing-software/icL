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
