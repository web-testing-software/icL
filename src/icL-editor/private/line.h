#ifndef icL_editor_Line
#define icL_editor_Line

#include <QObject>



class QTextStream;
class QStaticText;
class QPainter;

namespace icL::editor {

class Fragment;
class Logic;

class Line : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Fragment* first READ first  WRITE setFirst NOTIFY firstChanged)
	Q_PROPERTY(icL::editor::Line*      next READ next   WRITE setNext  NOTIFY nextChanged)
	Q_PROPERTY(icL::editor::Line*      prev READ prev   WRITE setPrev  NOTIFY prevChanged)
	Q_PROPERTY(icL::editor::Logic*  parent READ parent NOTIFY parentChanged)

	Q_PROPERTY(uint8_t     length READ length     NOTIFY lengthChanged)
	Q_PROPERTY(int32_t   beginPos READ beginPos   WRITE setBeginPos   NOTIFY beginPosChanged)
	Q_PROPERTY(int16_t lineNumber READ lineNumber WRITE setLineNumber NOTIFY lineNumberChanged)
	Q_PROPERTY(bool       visible READ visible    WRITE setVisible    NOTIFY visibleChanged)
	// clang-format on

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
	 * @brief getText gets the text of line by concatenation all fragments
	 * @return the text of line
	 */
	const QString & getText();

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

signals:
	void firstChanged(Fragment * first);
	void lengthChanged(uint8_t length);
	void beginPosChanged(int32_t beginPos);
	void lineNumberChanged(int16_t lineNumber);
	void visibleChanged(bool visible);
	void nextChanged(Line * next);
	void prevChanged(Line * prev);
	void parentChanged(Logic * parent);

public slots:
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
	 * @brief makeChanged sets up the changed state
	 */
	void makeChanged();

	/**
	 * @brief charsNumberInLineNumber helps to align to right line number
	 * @return return the number of charaters in line number
	 */
	int charsNumberInLineNumber();

private:
	Fragment * m_first = nullptr;
	Line *     m_next  = nullptr;
	Line *     m_prev  = nullptr;

	uint8_t m_length;
	int32_t m_beginPos;
	int16_t m_lineNumber;
	bool    m_visible = false;

	// fields
	bool    m_isChanged = false;
	QString content;
	Logic * m_parent;

	/// @brief cache is the geometry of line number
	QStaticText * cache = nullptr;

	int m_charsNumberInLineNumber = 0;
};

}  // namespace icL::editor

#endif  // icL_editor_Line
