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
	~InternalChange();

	/**
	 * @brief hasInsert returns true if chages has some insertions
	 * @return true if chages has some insertions
	 */
	bool hasInsert();

	/**
	 * @brief markInsert marks that the changes has insertions now
	 */
	void markInsert();

	void addChange(int line, int column, bool isMain);

	void dropChange(int line, int column, bool isMain);

	/**
	 * @brief getChanges returns the list of changes
	 * @return the list of changes
	 */
	const QLinkedList<ChangeEntity *> getChanges();

	// Revision interface
public:
	void undo(Logic * logic) override;
	void redo(Logic * logic) override;

private:
	/// \brief changes is the list of changes in project
	QLinkedList<ChangeEntity *> changes;

	/// \brief droppedChanges is the list of changes of dropped cursors
	QLinkedList<ChangeEntity *> droppedChanges;

	/// \brief m_hasInsert defines if the changes has some inserted text
	bool m_hasInsert = false;
};

}  // namespace icL::editor

#endif  // icL_editor_InternalChange
