#ifndef icL_editor_InternalChange
#define icL_editor_InternalChange

#include "revision.h"

#include <QLinkedList>
#include <QString>



namespace icL::editor {

class Selection;

/**
 * @brief The ChangeEntity struct defines a change entity, the entities can be
 * more then one (in the multicursor mode)
 */
struct ChangeEntity
{
	/// \brief inserted is the inerted text
	QString inserted;
	/// \brief deleted is the deleted text
	QString deleted;
	/// \brief line is the number of line
	int line;
	/// \brief column is the column of cursor
	int column;
	/// \brief isMain is true for main cursor, otherwise false
	bool isMain;
	/// \brief selection is the selection to undo/redo changes
	Selection * selection = nullptr;

	ChangeEntity(int line, int column, bool isMain);
};

class InternalChange : public Revision
{
public:
	InternalChange();

	// Revision interface
public:
	void undo(Logic * logic) override;
	void redo(Logic * logic) override;

	const QLinkedList<ChangeEntity *> getChanges();

private:
	QLinkedList<ChangeEntity *> changes;
};

}  // namespace icL::editor

#endif  // icL_editor_InternalChange
