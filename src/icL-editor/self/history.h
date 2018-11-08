#ifndef icL_editor_History
#define icL_editor_History

#include "scroll.h"



namespace icL::editor {

/**
 * @brief The History class contains the history of document
 */
class History : public Scroll
{
	Q_OBJECT

public:
	explicit History(QQuickItem * parent = nullptr);

protected:
	/**
	 * @brief addCursorOnPrevLine adds a new cursor on previous line
	 *
	 * Adds a new cursor on current line and moves the main on previous line, if
	 * the previous line has no a cursor yet. Otherwise it removes the cursor
	 * from prev line and moves the main to it.
	 */
	void addCursorOnPrevLine();

	/**
	 * @brief addCursorOnNextLine adds a new cursor to next line
	 *
	 * Adds a new cursor on current line and moves the main on next line, if the
	 * next line has no a cursor yet. Otherwise it removes the cursor from next
	 * line and moves the main to it.
	 */
	void addCursorOnNextLine();

protected:
	/**
	 * @brief numberOfCursors is the number of cursors in the text editor
	 */
	int numberOfCursors = 0;
};

}  // namespace icL::editor

#endif  // icL_editor_History
