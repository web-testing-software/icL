#ifndef icL_editor_Selection
#define icL_editor_Selection

#include <QObject>

namespace icL::editor {

class Selection : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Cursor*   begin READ begin WRITE setBegin NOTIFY beginChanged)
	Q_PROPERTY(icL::editor::Cursor*     end READ end   WRITE setEnd   NOTIFY endChanged)
	Q_PROPERTY(icL::editor::Selection* next READ next  WRITE setNext  NOTIFY nextChanged)

	Q_PROPERTY(bool rtl READ rtl WRITE setRtl NOTIFY rtlChanged)
	// clang-format on

public:
	explicit Selection(QObject *parent = nullptr);

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

public slots:
};

} // namespace

#endif // icL_editor_Selection
