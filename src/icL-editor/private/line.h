#ifndef icL_editor_Line
#define icL_editor_Line

#include <QObject>



class QTextStream;
class QStaticText;
class QPainter;

namespace icL::editor {

class Fragment;
class Logic;

class Line
{
public:
	explicit Line(Logic * parent = nullptr);

	/**
	 * @brief first gets the first fragment in the line
	 * @return the first fragment in the line
	 */
	Fragment * first() const;

	/**
	 * @brief next gets the next line
	 * @return the next line
	 */
	Line * next() const;

	/**
	 * @brief prev gets the previous line
	 * @return the previous line
	 */
	Line * prev() const;

	/**
	 * @brief length gets the length of the line
	 * @return the lenght of the line
	 */
	uint8_t length() const;

	/**
	 * @brief beginPos is the begin pselectionosition of the line
	 * @return the begin position of text fragment
	 */
	int32_t beginPos() const;

	/**
	 * @brief lineNumber return the line number
	 * @return the number of line
	 */
	int16_t lineNumber() const;

	/**
	 * @brief visible gets the visible state of line
	 * @return true if line is visible, otherwise false
	 */
	bool visible() const;

	/**
	 * @brief hasBreakPoint gets the breaking property of line
	 * @return true if need to break, otherwise false
	 */
	bool hasBreakPoint() const {
		return m_hasBreakPoint;
	}

	/**
	 * @brief getText gets the text of line by concatenation all fragments
	 * @return the text of line
	 */
	const QString & getText(bool force = false);

	/**
	 * @brief isChanged gets the changed state
	 * @return true id is changed, otherwise false
	 */
	bool isChanged();

	/**
	 * @brief save saves the line content to file
	 * @param straem is the strem to send in the text
	 */
	void save(QTextStream * stream);

	/**
	 * @brief parent is the editor of line
	 * @return the editor of line
	 */
	Logic * parent() const;

	/**
	 * @brief getCache return the cache of line number
	 * @return the pointer to cache of line number
	 */
	QStaticText * getCache();

	/**
	 * @brief updateLength recalc the length of line
	 */
	void updateLength();

public:
	/**
	 * @brief setFirst sets the first fragment of line
	 * @param first is the new first fragment
	 */
	void setFirst(Fragment * first);

	/**
	 * @brief setNext sets the next line
	 * @param next is the new next line
	 */
	void setNext(Line * next);

	/**
	 * @brief setPrev sets the previous line
	 * @param prev is the new previous line
	 */
	void setPrev(Line * prev);

	/**
	 * @brief setBeginPos changes the begin pos of line
	 * @param beginPos is the new begin position
	 */
	void setBeginPos(int32_t beginPos);

	/**
	 * @brief setLineNumber changes the number of line
	 * @param lineNumber is the new line number
	 */
	void setLineNumber(int16_t lineNumber);

	/**
	 * @brief setVisible hides/shows the line
	 * @param visible is true on show and false on hide
	 */
	void setVisible(bool visible);

	/**
	 * @brief setHasBreakPoint changes the break necesity
	 * @param hasBreakPoint is true if need to break, otherwise false
	 */
	void setHasBreakPoint(bool hasBreakPoint);

	/**
	 * @brief makeChanged sets up the changed state
	 */
	void makeChanged();

	/**
	 * @brief fixLine fixes lines from this to last
	 */
	void fixLines();

	/**
	 * @brief charsNumberInLineNumber helps to align to right line number
	 * @return return the number of charaters in line number
	 */
	int8_t charsNumberInLineNumber();

private:
	// Properties
	Fragment * m_first = nullptr;
	Line *     m_next  = nullptr;
	Line *     m_prev  = nullptr;

	uint8_t m_length = 0;
	int32_t m_beginPos{};
	int16_t m_lineNumber{};
	bool    m_visible = false;

	// fields

	/// @brief The line has unsaved chaghes
	bool m_isChanged = false;

	/// @brief Text content of the line
	QString content;

	/// @brief The editor which contains this line
	Logic * m_parent;

	/// @brief cache is the geometry of line number
	QStaticText * cache = nullptr;

	/// @brief The number of chars in line number
	int8_t m_charsNumberInLineNumber = 0;

	/// @brief This line has a break point
	bool m_hasBreakPoint = false;
};

}  // namespace icL::editor

#endif  // icL_editor_Line
