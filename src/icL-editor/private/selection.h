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

public:
	explicit Selection(QObject * parent = nullptr);

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
	 * @brief insert inserts text be replacing the selected text
	 * @param text is the text to insert
	 * @return the inserted text
	 */
	QString insert(const QString & text);

signals:
	void beginChanged(Cursor * begin);
	void endChanged(Cursor * end);
	void nextChanged(Selection * next);
	void rtlChanged(bool rtl);

public slots:
	/**
	 * @brief setNext add a new selection to collection
	 * @param next is the new selection in collection
	 */
	void setNext(Selection * next);

	/**
	 * @brief setRtl change the main cursor
	 * @param rtl if true use left, otherwise use right
	 */
	void setRtl(bool rtl);

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

private:
	Cursor *    m_begin = nullptr;
	Cursor *    m_end   = nullptr;
	Selection * m_next  = nullptr;
	bool        m_rtl{};
};

}  // namespace icL::editor

#endif  // icL_editor_Selection
