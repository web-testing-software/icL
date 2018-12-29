#include "externalchanges.h"

#include "../fragment/fragment.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "../self/logic.h"

namespace icL::editor {

ExternalChanges::ExternalChanges() = default;

void ExternalChanges::undo(Logic * logic) {
	restoreFrom(logic, before);
}

void ExternalChanges::redo(Logic * logic) {
	restoreFrom(logic, after);
}

void ExternalChanges::restoreFrom(Logic * logic, QLinkedList<QString> & list) {

	auto * line = logic->first();
	auto   it   = list.begin();

	logic->lBackUpSelections();

	while (line != nullptr && it != list.end()) {
		line->replaceContents(*it);
	}

	while (line->next() != nullptr) {
		line->next()->deleteNow();
	}

	if (it != list.end()) {
		QString toPaste = "\n";

		while (it != list.end()) {
			toPaste += '\n' + *it;
		}

		line->first()->rawInsert(
		  logic->main()->end(), line->first()->length(), toPaste);
	}

	logic->lRestoreSeletions();
	logic->lOptimizeSelections();
}

}  // namespace icL::editor
