#ifndef icL_editor_ExternalChanges
#define icL_editor_ExternalChanges

#include "revision.h"

#include <QLinkedList>

namespace icL::editor {

class ExternalChanges : public Revision
{
public:
	ExternalChanges();

	// Revision interface
public:
	void undo(Logic * logic) override;
	void redo(Logic * logic) override;

private:
	QLinkedList<QString> before;
	QLinkedList<QString> after;
};

}  // namespace icL::editor

#endif  // icL_editor_ExternalChanges
