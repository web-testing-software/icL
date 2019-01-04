#ifndef icL_editor_Selection
#define icL_editor_Selection

#include <QString>



namespace icL::editor {

class Cursor;
class Line;

struct ChangeEntity;

/**
 * @brief The Selection class describes a selection of text
 */
class Selection
{
public:
	explicit Selection();

	~Selection();

	/**
	 * @brief begin is the begin of selection
	 * @return the begin of selection
	 */
	Cursor * begin() const;

	/**
	 * @brief end is the end of selection
	 * @return the end of selection
	 */
	Cursor * end() const;

	/**
	 * @brief main returns the main cursor of selection
	 * @return m_begin if rtl == true, otherwise m_end
	 */
	Cursor * main() const;

	/**
	 * @brief next is prev linked selection
	 * @return the prev linked selection
	 */
	Selection * prev() const;

	/**
	 * @brief next is next linked selection
	 * @return the next linked selection
	 */
	Selection * next() const;

	/**
	 * @brief rtl is the direction of selection
	 * @return the direction of selection
	 */
	bool rtl() const;

	/**
	 * @brief getText returns the selected text
	 * @return the selected text
	 */
	QString getText();

	/**
	 * @brief getChangeEntity gets the change entity
	 * @return the change entity of this selection
	 * @note strong use just from History class
	 */
	ChangeEntity * getChangeEntity();

	/**
	 * @brief move moves the cursor to left/right be needed chars
	 * @param step is the number of chars
	 * @param select is the selection mode flag
	 */
	void move(int step, bool select = false);

	/**
	 * @brief moveOverWords moves the cursor to left/right by needed words
	 * @param words is the words count
	 * @param select is the selection mode frag
	 */
	void moveOverWords(int words, bool select = false);

	/**
	 * @brief moveUpDown move cursor up/down to others lines
	 * @param lines is the number of lines to skip
	 * @param select is the selection mode flag
	 */
	void moveUpDown(int lines, bool select = false);

	/**
	 * @brief drop drops all selected text (fragment by fragment)
	 * @return the deleted text
	 */
	QString drop();

	/**
	 * @brief backspace remove the symbol on the left of cursor
	 * @return the deleted text
	 */
	QString backspace();

	/**
	 * @brief delete1 remove the symbol on the right of cursor
	 * @return the deleted text
	 */
	QString delete1();

	/**
	 * @brief insert inserts text
	 * @param text is the text to insert
	 * @return the inserted text
	 */
	QString insert(const QString & text);

	/**
	 * @brief rawInsert inserts text
	 * @param text is the text to insert
	 * @note the text will be inserted as is, without modifications
	 */
	void rawInsert(const QString & text);

	/**
	 * @brief rawDrop drops the selected text
	 */
	void rawDrop();

	/**
	 * @brief linkAfter links a new selection after this
	 * @param selection is the selection to link
	 */
	void linkAfter(Selection * selection);

	/**
	 * @brief linkBefore links a new selection before this
	 * @param selection is the selection to link
	 */
	void linkBefore(Selection * selection);

	/**
	 * @brief remove removes this selection from linked list
	 */
	void remove();

	/**
	 * @brief syncWith syncs this selection with selection
	 * @param selection is the selection to sync with
	 */
	void syncWith(Selection * selection);

public:
	/**
	 * @brief setNext sets the next selection in collection
	 * @param next is the new next selection in collection
	 */
	void setNext(Selection * next);

	/**
	 * @brief setPrev sets the prev selection is collection
	 * @param prev is the new previous selection in collection
	 */
	void setPrev(Selection * prev);

	/**
	 * @brief setRtl change the main cursor
	 * @param rtl if true use left, otherwise use right
	 */
	void setRtl(bool rtl);

	/**
	 * @brief setChangeEntity sets the change entity from History class
	 * @param changeEntity is the new change entity
	 * @note strong use just from History class
	 */
	void setChangeEntity(ChangeEntity * changeEntity);

	/**
	 * @brief beginSelection begin selection by mouse
	 * @param line is the line number to position the cursors
	 * @param ch is the character number to position the cursors
	 */
	bool beginSelection(Line * line, int ch);

	/**
	 * @brief selectTo selects text from fixed begin to new position
	 * @param line is the line number for end cursor
	 * @param ch is the character number to position the cursors
	 */
	void selectTo(Line * line, int ch);

	/**
	 * @brief finishSelection finish the selection process
	 *
	 * This selection may be merged and deleted, also this function may delete
	 * other selection if this is the main. Please be careful.
	 */
	void finishSelection();

private:
	/**
	 * @brief moveSelect moves the selection cursor
	 * @param step is the number of chars to skip
	 * @param begin is the cursor which mark the begin of selection
	 * @param end is the cursor which mark the end of selection
	 */
	void moveSelect(int step, Cursor * begin, Cursor * end);

	/**
	 * @brief moveSelectOverWords moves the selection cursor over words
	 * @param words is the number of words to skip
	 * @param begin is the cursor which mark the begin of selection
	 * @param end is the cursor which mark the end of selection
	 */
	void moveSelectOverWords(int words, Cursor * begin, Cursor * end);

	/**
	 * @brief moveSelectOverLines moves the selection cursor over lines
	 * @param lines is the number of lines to skip
	 * @param begin is the cursor which mark the begin of selection
	 * @param end is the cursor which mark the end of selection
	 */
	void moveSelectOverLines(int lines, Cursor * begin, Cursor * end);

	/**
	 * @brief unifyCursors place both cursors in one place
	 */
	void unifyCursors();

	/**
	 * @brief setRtlByStep set the rtl to true of false in depedent by step
	 * value
	 * @param step is a negative or positive number (not zero)
	 */
	void setRtlByStep(int step);

	/**
	 * @brief moveCursorToLine moves cursor to begin in nth line
	 * @param line is the line numbers
	 * @param cursor is the cursor which need move
	 * @return true if so line was found, otherwise false
	 */
	bool moveCursorToLine(Line * line, Cursor * cursor);

	/**
	 * @brief isAfter if the cursor is after the position described by line/ch
	 * @param cursor the cursor to compare
	 * @param line the line number of new position
	 * @param ch the charanter number of position
	 * @return true if is (line, ch) is after cursor, otherwise false
	 */
	bool isAfter(Cursor * cursor, Line * line, int ch);

private:
	/// @brief m_begin is the cursor which describes the begin of seletion
	Cursor * m_begin = nullptr;

	/// @brief m_end is the cursor which descrines the end of selection
	Cursor * m_end = nullptr;

	/// @brief m_prev is the previous active selection in document
	Selection * m_prev = nullptr;

	/// @brief m_next is the next active selection in document
	Selection * m_next = nullptr;

	/// @brief when rtl = false, the main cursor is the end, otherwise to begin
	///
	/// rtl means Right-To-Left
	bool m_rtl = false;

	/// \brief changeEntity will be used by History class
	ChangeEntity * changeEntity;
};

}  // namespace icL::editor

#endif  // icL_editor_Selection
