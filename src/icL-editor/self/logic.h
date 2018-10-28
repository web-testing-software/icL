#ifndef icL_editor_Logic
#define icL_editor_Logic

#include <QQuickPaintedItem>



class QStaticText;

namespace icL::editor {

class Selection;
class Line;
class Fixer;

/**
 * @brief The Logic class contains the internal logic of editor
 */
class Logic : public QQuickPaintedItem
{
	Q_OBJECT

public:
	Logic(QQuickItem * parent);

	~Logic();

	/**
	 * @brief main is the main selection
	 * @return the main selection
	 */
	Selection * main() const;

	/**
	 * @brief first is the first line of text
	 * @return the first line of text
	 */
	Line * first() const;

	/**
	 * @brief current is the current line of text
	 * @return the current line of text
	 */
	Line * current() const;

	/**
	 * @brief firstVisible is the first visible line
	 * @return the first visible line
	 */
	Line * firstVisible() const;

	/**
	 * @brief lastVisible is the last visible line
	 * @return th elast visible line
	 */
	Line * lastVisible() const;

	/**
	 * @brief fixer gets the fixer of editor
	 * @return the fixer of this editor
	 */
	Fixer * fixer();

	/**
	 * @brief makeChanged set up the changed state of editor
	 */
	void makeChanged();

	/**
	 * @brief clear deletes all editor content
	 */
	void clear();

	/**
	 * @brief loadFile loads a file from disk
	 * @param path is the path of file
	 */
	Q_INVOKABLE bool loadFile(const QString & path);

public slots:
	/**
	 * @brief setFirst changes the pointer to the first line
	 * @param first is the new first line
	 */
	void setFirst(Line * first);

	/**
	 * @brief setCurrent changes the pointer to the current line
	 * @param current is the new current line
	 */
	void setCurrent(Line * current);

	/**
	 * @brief setFirstVisible changes the pointer to the fisrt visible line
	 * @param firstVisible is the new first visible line
	 */
	void setFirstVisible(Line * firstVisible);

	/**
	 * @brief setLastVisible changes the pointer to the last visible line
	 * @param lastVisible is the new last visible line
	 */
	void setLastVisible(Line * lastVisible);

	/**
	 * @brief addNewLine inserts a new line after the current
	 * @param line is the line to add
	 */
	void addNewLine(Line * line, bool focus = true);

	/**
	 * @brief updateCurrentLine update the pointer to the current line
	 */
	void updateCurrentLine();

protected:
	/**
	 * @brief changeNumberOfLines changes the numbers of lines
	 * @param newValue is the number of lines
	 */
	void changeNumberOfLines(int newValue);

	// properties
	Selection * m_main = nullptr;

	Line * m_first        = nullptr;
	Line * m_current      = nullptr;
	Line * m_firstVisible = nullptr;
	Line * m_lastVisible  = nullptr;

	// fields
	/// @brief changed confirm that the document was changed or not
	bool changed = false;

	/// @brief numberOfLines is the number of line in document
	int numberOfLines = 0;

	/// @brief numberOfDigits is the number of digits in line number
	int numberOfDigits = 0;

	/// @brief the line in which currently is placed the debug cursor
	Line * debugLine{};

	/// @brief the fixer to fix line numbers
	Fixer * m_fixer;
};

}  // namespace icL::editor

#endif  // icL_editor_Logic
