#include "externalchanges.h"

#include "../private/line.h"
#include "../self/logic.h"

namespace icL::editor {

ExternalChanges::ExternalChanges() {}

void ExternalChanges::undo(Logic * logic) {
	auto * line = logic->first();

	while (line != nullptr) {
		//        line->
	}
}

}  // namespace icL::editor
