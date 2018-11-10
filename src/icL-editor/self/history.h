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

	/**
	 * @brief getFirstSelection gets first selection from linked list
	 * @return the first selection from linked list
	 */
	Selection * getFirstSelection();

	/**
	 * @brief getLastSelection gets last selection from linked list
	 * @return the last selection from linked list
	 */
	Selection * getLastSelection();

	/**
	 * @brief selectionsCount gets the number of selections
	 * @return the number of selections
	 */
	int selectionsCount();

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
	int numberOfCursors = 1;
};

}  // namespace icL::editor

#endif  // icL_editor_History
