#ifndef icL_editor_Selection
#define icL_editor_Selection

#include <QObject>

namespace icL::editor {

class Cursor;

class Selection : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Cursor*   begin READ begin NOTIFY beginChanged)
	Q_PROPERTY(icL::editor::Cursor*     end READ end   NOTIFY endChanged)
	Q_PROPERTY(icL::editor::Selection* next READ next  WRITE setNext  NOTIFY nextChanged)

	Q_PROPERTY(bool rtl READ rtl WRITE setRtl NOTIFY rtlChanged)
	// clang-format on

	Cursor *    m_begin;
	Cursor *    m_end;
	Selection * m_next;

public:
	explicit Selection(QObject * parent = nullptr);

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
	 * @brief next is next linked selection
	 * @return the next linked selection
	 */
	Selection * next() const;

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

signals:
	void beginChanged(Cursor * begin);
	void endChanged(Cursor * end);
	void nextChanged(Selection * next);

public slots:
	/**
	 * @brief setNext add a new selection to collection
	 * @param next is the new selection in collection
	 */
	void setNext(Selection * next);
};

}  // namespace icL::editor

#endif  // icL_editor_Selection
