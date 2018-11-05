#ifndef icL_editor_Logic
#define icL_editor_Logic

#include <QQuickPaintedItem>



class QStaticText;

/**
 * @brief The icL.editor namespace contains all needed component to create a
 * modern and powerfull text editor
 */
namespace icL::editor {

class Selection;
class Line;
class Fixer;
class LineNumbers;

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

signals:
	/// @brief this signal is emited to redraw mask, line numbers and editor
	void requestRepaint();

	/// @brief elude QML warning
	void firstLineNrChanged();
	/// @brief elude QML warning
	void linesCountChanged();


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
	 * @brief addNewLine inserts a new line after the current
	 * @param line is the line to add
	 */
	void addNewLine(Line * line);

	/**
	 * @brief updateCurrentLine update the pointer to the current line
	 */
	void updateCurrentLine();

	/**
	 * @brief changeNumberOfLines changes the numbers of lines
	 * @param newValue is the number of lines
	 */
	void changeNumberOfLines(int newValue);

	/// @brief will be defined in Drawing class
	virtual int visbileLines() const = 0;
	/// @brief will be defined in Drawing class
	virtual void updateBackgroundGeometry() = 0;

protected:
	/// @brief will be defined in Scroll class
	virtual void scrollUpBy(int by) = 0;
	/// @brief will be defined in Scroll class
	virtual void scrollDownBy(int by) = 0;
	/// @brief will be defined in Scroll class
	virtual void autoScrollToCurrent() = 0;

protected:
	// properties
	/// @brief the main selection (never deleted)
	Selection * m_main = nullptr;

	/// @brief the first line of text
	Line * m_first = nullptr;

	/// @brief the current line of text
	Line * m_current = nullptr;

	/// @brief the first visible line of text
	Line * m_firstVisible = nullptr;

	// fields
	/// @brief changed confirm that the document was changed or not
	bool changed = false;

	/// @brief numberOfLines is the number of line in document
	int numberOfLines = 0;

	/// @brief numberOfDigits is the number of digits in line number
	int numberOfDigits = 0;

	/// @brief the line in which currently is placed the debug cursor
	Line * debugLine = nullptr;

	/// @brief the fixer to fix line numbers
	Fixer * m_fixer = nullptr;
};

}  // namespace icL::editor

#endif  // icL_editor_Logic
