#ifndef icL_editor_ExternalChanges
#define icL_editor_ExternalChanges

#include "revision.h"

#include <QLinkedList>

namespace icL::editor {

/**
 * @brief The ExternalChanges class describes a chanes of file reload after
 * external changes
 */
class ExternalChanges : public Revision
{
public:
	ExternalChanges();

	// Revision interface
public:
	void undo(Logic * logic) override;
	void redo(Logic * logic) override;

private:
	/**
	 * @brief restoreFrom restores the editor content from string list
	 * @param is the list of content
	 */
	void restoreFrom(Logic * logic, QLinkedList<QString> & list);

	/// \brief before is the content before changes
	QLinkedList<QString> before;

	/// \brief after is the content after changes
	QLinkedList<QString> after;
};

}  // namespace icL::editor

#endif  // icL_editor_ExternalChanges
