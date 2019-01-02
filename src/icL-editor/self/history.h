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
	Selection * hGetFirstSelection();

	/**
	 * @brief getLastSelection gets last selection from linked list
	 * @return the last selection from linked list
	 */
	Selection * hGetLastSelection();

	/**
	 * @brief selectionsCount gets the number of selections
	 * @return the number of selections
	 */
	int hSelectionsCount();

protected:
	/**
	 * @brief addCursorOnPrevLine adds a new cursor on previous line
	 *
	 * Adds a new cursor on current line and moves the main on previous line, if
	 * the previous line has no a cursor yet. Otherwise it removes the cursor
	 * from prev line and moves the main to it.
	 */
	void hAddCursorOnPrevLine();

	/**
	 * @brief addCursorOnNextLine adds a new cursor to next line
	 *
	 * Adds a new cursor on current line and moves the main on next line, if the
	 * next line has no a cursor yet. Otherwise it removes the cursor from next
	 * line and moves the main to it.
	 */
	void hAddCursorOnNextLine();

	/**
	 * @brief moveCursorToNextChar moves the cursors over `step` charactera
	 *
	 * The position of cursor must be tracked
	 */
	void hMoveCursorChar(int step);

	/**
	 * @brief moveCursorToNextWord moves the cursors over `step` words
	 */
	void hMoveCursorWord(int step);

	/**
	 * @brief hMoveCursorLine moves the cursors over `step` lines
	 */
	void hMoveCursorLine(int step);

	/**
	 * @brief hSelectChar moves the cursor over `step` chars selecting text
	 */
	void hSelectChar(int step);

	/**
	 * @brief hSelectWord moves the cursor over `step` words selecting text
	 */
	void hSelectWord(int step);

	/**
	 * @brief hSelectLine moves the cursor over `step` lines selecting text
	 */
	void hSelectLine(int step);

	/**
	 * @brief hBackspace removes the left character
	 */
	void hBackspace();

	/**
	 * @brief hDelete removes the right character
	 */
	void hDelete();

	/**
	 * @brief hDrop removes the selected text
	 */
	void hDrop();

	/**
	 * @brief hInsert insert the text to editor
	 */
	void hInsert();

	/**
	 * @brief hUndo cancel the last change
	 */
	void hUndo();

	/**
	 * @brief hRedo repeat the last change
	 */
	void hRedo();

	/**
	 * @brief tryToDelete delete selections if they are not empty
	 */
	void hTryToDelete();

	/**
	 * @brief hasSelection return true if there is a non empty selections
	 * @return true if there is a non empty selection, otherwise false
	 */
	bool hHasSelection();

	/**
	 * @brief hUpdateHistories update the shadows of cursors in history
	 */
	void hUpdateHistories();

	/**
	 * @brief hFixSelections removes useless selections and unite intersections
	 */
	void hFixSelections();

	/**
	 * @brief getCurrent returns or create a new change entity
	 * @param forDelete true if it is need for deletion, false - for insertion
	 * @return a new or existent changes entity
	 */
	InternalChange * hGetCurrentChangeEntity(bool forDelete);

	/**
	 * @brief getNewChangeEntity return a new inited change entity
	 * @return a new inited change entity
	 */
	InternalChange * hGetNewChangeEntity();

protected:
	/// \brief numberOfCursors is the number of cursors in the text editor
	int numberOfCursors = 1;

private:
	/// \brief m_currentChange is the pointer to current change
	InternalChange * m_currentChange = nullptr;

	/// \brief cursorWasMoved detect if the cursor was moved, it means that the
	/// change entity must be updated
	bool cursorWasMoved = false;
};

}  // namespace icL::editor

#endif  // icL_editor_History
