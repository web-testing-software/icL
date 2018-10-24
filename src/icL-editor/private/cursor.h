#ifndef icL_editor_Cursor
#define icL_editor_Cursor

#include <QObject>

namespace icL::editor {

class Fragment;
class Advanced;

class Cursor : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Fragment* fragment READ fragment WRITE setFragment NOTIFY fragmentChanged)

	Q_PROPERTY(int8_t   position READ position  WRITE setPosition  NOTIFY positionChanged)
	Q_PROPERTY(uint8_t preffered READ preffered WRITE setPreffered NOTIFY prefferedChanged)
	// clang-format on

public:
	explicit Cursor(QObject * parent = nullptr);

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
	bool stepBack(int number, Cursor * block);

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
	bool stepWordBack(Cursor * block);

	/**
	 * @brief syncWith syncronize the position of cursors
	 * @param cursor is the cursor to sync with
	 */
	void syncWith(Cursor * cursor);

	Advanced * getEditor();

signals:
	void fragmentChanged(Fragment * fragment);
	void positionChanged(int8_t position);
	void prefferedChanged(uint8_t preffered);

public slots:
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
	Fragment * m_fragment = nullptr;
	int8_t     m_position;
	uint8_t    m_preffered;
};

}  // namespace icL::editor

#endif  // icL_editor_Cursor
