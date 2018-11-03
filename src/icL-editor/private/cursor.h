#ifndef icL_editor_Cursor
#define icL_editor_Cursor

#include <stdint.h>



namespace icL::editor {

class Fragment;
class EditorInternal;
class Line;

/**
 * @brief The Cursor class describes a cursor in editor
 */
class Cursor
{
public:
	Cursor() = default;

	/**
	 * @brief fragment gets the fragment of cursor
	 * @return the fragment of cursor
	 */
	Fragment * fragment() const;

	/**
	 * @brief position gets the position in text fragment
	 * @return the position in text fragment
	 */
	int8_t position() const;

	/**
	 * @brief preffered gets the preffered absolute position
	 * @return the preffered absolute position
	 */
	uint8_t preffered() const;

	/**
	 * @brief getPosInLine gets the position in line
	 * @return the position of cursor in line
	 */
	int getPosInLine();

	/**
	 * @brief getPosInFile gets the position in file
	 * @return the position of cursor in file
	 */
	int getPosInFile();

	/**
	 * @brief stepForward moves the cursor forward
	 * @param number is the number of chars to skip
	 * @param block blocks the moving of cursor movies over it
	 * @return true if moved successful, otherwise false
	 */
	bool stepForward(int number, Cursor * block);

	/**
	 * @brief stepBack moves the cursor back
	 * @param number is the number of chars to skip
	 * @param block blocks the moving of cursor movies over it
	 * @return true if moved successful, otherwise false
	 */
	bool stepBackward(int number, Cursor * block);

	/**
	 * @brief stepWordForward step the next word
	 * @param block blocks the moving of cursor movies over it
	 * @return true if moved successful, otherwise false
	 */
	bool stepWordForward(Cursor * block);

	/**
	 * @brief stepWordBack step the prev word
	 * @param block blocks the moving of cursor movies over it
	 * @return true if moved successful, otherwise false
	 */
	bool stepWordBackward(Cursor * block);

	/**
	 * @brief stepWordsForward runs stepWordForward n times
	 * @param words is the count of runs
	 * @param block blocks the moving of cursor movies over it
	 * @return true if moved successful, otherwise false
	 */
	bool stepWordsForward(int words, Cursor * block);

	/**
	 * @brief stepWordsBackward runs stepWordBackward n times
	 * @param words is the count of runs
	 * @param block blocks the moving of cursor movies over it
	 * @return true if moved successful, otherwise false
	 */
	bool stepWordsBackward(int words, Cursor * block);

	/**
	 * @brief moveToLine moves to cursor to needed line
	 * @param line is the lien to move in
	 */
	void moveToLine(Line * line);

	/**
	 * @brief stepLinesUp moves the cursor up skipping n lines
	 * @param lines is the count of lines
	 * @param block blocks the moving of cursor movies over it
	 * @return true if moved successful, otherwise false
	 */
	bool stepLinesUp(int lines, Cursor * block);

	/**
	 * @brief stepLinesDown moves the cursor down skipping n lines
	 * @param lines is the count of lines
	 * @param block blocks the moving of cursor movies over it
	 * @return true if moved successful, otherwise false
	 */
	bool stepLinesDown(int lines, Cursor * block);

	/**
	 * @brief syncWith syncronize the position of cursors
	 * @param cursor is the cursor to sync with
	 */
	void syncWith(Cursor * cursor);

	/**
	 * @brief updatePreffered update the preffered position in line
	 * @param delta if 0 autoupdate, otherwise move be specified delta
	 */
	void updatePreffered(int delta = 0);

	/**
	 * @brief matchPreffered try to move cursor to prefered position
	 */
	void matchPreffered();

	/**
	 * @brief getEditor gets the pointer to editor
	 * @return the pointer to editor
	 */
	EditorInternal * getEditor();

	/**
	 * @brief operator == compare position of cursors
	 * @param other is the cursor to compare with
	 * @return true if both are place in on place, otherwise false
	 */
	bool operator==(const Cursor & other) const;

	/**
	 * @brief operator != compare position of cursors
	 * @param other is the cursor to compare with
	 * @return false if both are place in on place, otherwise true
	 */
	bool operator!=(const Cursor & other) const;

public:
	/**
	 * @brief setFragment sets the text fragment
	 * @param fragment is the new text fragment (it cannot be null)
	 */
	void setFragment(Fragment * fragment);

	/**
	 * @brief setPosition set the position in fragment
	 * @param position is the new position in fragment
	 */
	void setPosition(int8_t position);

	/**
	 * @brief setPreffered set the preffered absolute position
	 * @param preffered is the new preffered position
	 */
	void setPreffered(uint8_t preffered);

private:
	// Properties

	/// @brief fragment of text in which the cursor in placed
	Fragment * m_fragment = nullptr;

	/// @brief the relative position to fragment begin
	int8_t m_position = 0;

	/// @brief the preffered postiotion relative to line (!fragment) begin
	uint8_t m_preffered = 0;
};

}  // namespace icL::editor

#endif  // icL_editor_Cursor
