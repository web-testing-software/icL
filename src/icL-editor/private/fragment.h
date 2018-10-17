#ifndef icL_editor_Fragment
#define icL_editor_Fragment

#include <QObject>



class QStaticText;

namespace icL::editor {

class Line;

class Fragment : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Fragment* prev READ prev WRITE setPrev NOTIFY prevChanged)
	Q_PROPERTY(icL::editor::Fragment* next READ next WRITE setNext NOTIFY nextChanged)
	Q_PROPERTY(icL::editor::Line*     line READ line WRITE setLine NOTIFY lineChanged)

	Q_PROPERTY(uint8_t length READ length NOTIFY lengthChanged)
	Q_PROPERTY(int8_t  spaces READ spaces NOTIFY spacesChanged)
	Q_PROPERTY(int8_t  glyphs READ glyphs NOTIFY glyphsChanged)
	// clang-format on

public:
	explicit Fragment(QObject * parent = nullptr);

	/**
	 * @brief prev is the previous sibling
	 * @return the previous sibling
	 */
	Fragment * prev() const;

	/**
	 * @brief next is the next sibling
	 * @return the next sibling
	 */
	Fragment * next() const;

	/**
	 * @brief line is the line which contains this fragment
	 * @return the line of fragment
	 */
	Line * line() const;

	/**
	 * @brief length is the length of fragment (spaces + glyphs)
	 * @return the length of fragment
	 */
	uint8_t length() const;

	/**
	 * @brief spaces is the number of spaces before glyphs
	 * @return the number of spaces before glyphs
	 */
	int8_t spaces() const;

	/**
	 * @brief glyphs is the number of glyphs
	 * @return the number of glyphs
	 */
	int8_t glyphs() const;

	/**
	 * @brief displayText gets the text to display
	 * @return the text to display
	 */
	virtual const QString & displayText();

	/**
	 * @brief nextFragment gets the next fragment, from current or next line
	 * @return the next text fragment (is not always a sibling)
	 */
	Fragment * nextFragment();

	/**
	 * @brief prevFragment gets the prev fragment, from current or prev line
	 * @return the prev text fragment (is not always a sibling)
	 */
	Fragment * prevFragment();

	/**
	 * @brief isCached get the cache state (active or inactive)
	 * @return the cache active state
	 */
	bool isCached();

	/**
	 * @brief cacheNow caches the text geometry now
	 */
	void cacheNow();

	/**
	 * @brief freeCache free the cached geometry
	 */
	void freeCache();

	/**
	 * @brief getCache return a pointer to current cache
	 * @return nullptr is no cache is aviable
	 */
	const QStaticText * getCache();

	/**
	 * @brief drop deletes a fragment from text fragment
	 * @param begin the begin position
	 * @param end the end position
	 */
	void drop(int begin = 0, int end = -1);

	/**
	 * @brief insert inserts a text to needed position
	 * @param pos is the position to insert in
	 * @param text is the text to insert
	 */
	virtual void insert(int pos, const QString & text);

	/**
	 * @brief replace repalces a fragment of the be a new one
	 * @param p1 is the begin of interval
	 * @param p2 is the end of interval
	 * @param after is the new text
	 */
	virtual void replace(int p1, int p2, const QString & after);

signals:
	void prevChanged(Fragment * prev);
	void nextChanged(Fragment * next);
	void lineChanged(Line * line);
	void lengthChanged(uint8_t length);
	void spacesChanged(int8_t spaces);
	void glyphsChanged(int8_t glyphs);

public slots:
	/**
	 * @brief setPrev changes the previous sibling fragment
	 * @param prev is the new previous sibling fragment
	 */
	void setPrev(Fragment * prev);

	/**
	 * @brief setNext changes the next sibling fragment
	 * @param next is the new next sibling fragment
	 */
	void setNext(Fragment * next);

	/**
	 * @brief setLine chages the parent of fragment
	 * @param line is the new parent of fragment
	 */
	void setLine(Line * line);

private:
	// Properties
	Fragment * m_prev = nullptr;
	Fragment * m_next = nullptr;
	Line *     m_line = nullptr;

	uint8_t m_length;
	int8_t  m_spaces;
	int8_t  m_glyphs;

	// fields
	QStaticText * cache = nullptr;
	QString       content;
};



}  // namespace icL::editor

#endif  // icL_editor_Fragment
