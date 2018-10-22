#ifndef icL_editor_Fragment
#define icL_editor_Fragment

#include <QObject>



class QStaticText;

namespace icL::editor {

class Line;
class Advanced;

/**
 * @brief The ProcessedGlyphs struct describes a processed glyphs result
 */
struct ProcessedGlyphs
{
	/**
	 * @brief toInsertHere are the glyphs to insert in current fragment
	 */
	QString toInsertHere;

	/**
	 * @brief toInsertInNext are the glyphs to insert in a new fragment
	 */
	QString toInsertInNext;

	/**
	 * @brief onNextLine the new fragment must be on new line
	 */
	bool onNextLine;
};

enum class FragmentTypes { Fragment, Word, String, Bracket };

class Fragment : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Fragment* prev READ prev WRITE setPrev NOTIFY prevChanged)
	Q_PROPERTY(icL::editor::Fragment* next READ next WRITE setNext NOTIFY nextChanged)
	Q_PROPERTY(icL::editor::Line*     line READ line WRITE setLine NOTIFY lineChanged)

	Q_PROPERTY(uint8_t length READ length NOTIFY lengthChanged)
	Q_PROPERTY(uint8_t spaces READ spaces NOTIFY spacesChanged)
	Q_PROPERTY(uint8_t glyphs READ glyphs NOTIFY glyphsChanged)
	// clang-format on

public:
	explicit Fragment(Line * parent = nullptr);

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
	uint8_t spaces() const;

	/**
	 * @brief glyphs is the number of glyphs
	 * @return the number of glyphs
	 */
	uint8_t glyphs() const;

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
	Fragment * drop(int begin = 0, int end = -1);

	/**
	 * @brief insert inserts a text to needed position
	 * @param pos is the position to insert in
	 * @param text is the text to insert
	 */
	Fragment * insert(int pos, const QString & text);

	/**
	 * @brief replace repalces a fragment of the be a new one
	 * @param p1 is the begin of interval
	 * @param p2 is the end of interval
	 * @param after is the new text
	 */
	Fragment * replace(int p1, int p2, const QString & after);

	/**
	 * @brief isBracket detects if this fragment is a bracket
	 * @return true if this fragment is a bracket, otherwise false
	 */
	virtual bool isBracket();

	/**
	 * @brief isOpenBracket detects if this fragment is a open bracket
	 * @return true if this fragment is a open bracket, otherwise false
	 */
	virtual bool isOpenBracket();

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

protected:
	/**
	 * @brief getEditor returns the editor of fragment
	 * @return the editor of fragment
	 */
	Advanced * getEditor();

	/**
	 * @brief processGlyphs process the glyphs which must be inserted
	 * @param text is the glyphs itself
	 * @return the glyphs which will be inserted here and in the next fragment
	 */
	virtual ProcessedGlyphs processGlyphs(const QString & text);

	/**
	 * @brief insertInSpaces insert glyphs beetwen fragment spaces
	 * @param pos is the position of insertion
	 * @param text is the text to insert
	 */
	virtual Fragment * insertInSpaces(int pos, const QString & text);

	/**
	 * @brief insertAfterSpaces prepends glyphs to content
	 * @param pos is the position of insertion
	 * @param text is the text to insert
	 */
	virtual Fragment * insertAfterSpaces(const QString & text);

	/**
	 * @brief insertInGlyphs inserts glyphs in content
	 * @param pos is the position of insertion
	 * @param text is the text to insert
	 */
	virtual Fragment * insertInGlyphs(int pos, const QString & text);

	/**
	 * @brief insertAfterGlyphs appends glyphs after content
	 * @param pos is the position of insertion
	 * @param text is the text to insert
	 */
	virtual Fragment * insertAfterGlyphs(const QString & text);

	/**
	 * @brief dropSpaces removes spaces
	 * @param p1 is the index of first selected character
	 * @param p2 is the index of last selected character
	 */
	virtual Fragment * dropSpaces(int p1, int p2);

	/**
	 * @brief dropHead removes spaces and content glyphs
	 * @param p1 is the index of first selected character
	 * @param p2 is the index of last selected character
	 */
	virtual Fragment * dropHead(int p1, int p2);

	/**
	 * @brief dropContent removes content fragment
	 * @param p1 is the index of first selected character
	 * @param p2 is the index of last selected character
	 */
	virtual Fragment * dropContent(int p1, int p2);

	/**
	 * @brief dropTail removes the end of content
	 * @param p1 is the index of first selected character
	 * @param p2 is the index of last selected character
	 */
	virtual Fragment * dropTail(int p1, int p2);

	/**
	 * @brief dropAllContent removes all content of the fragment
	 * @param p1 is the index of first selected character
	 * @param p2 is the index of last selected character
	 */
	virtual Fragment * dropAllContent(int p1);

private:
	/**
	 * @brief makeNewFragment creates a new fragment of text in editor
	 * @param text is the text of the new fragment
	 * @param onNewLine if true creates the fragment on a new line
	 * @return the new created fragment
	 */
	Fragment * makeNewFragment(const QString & text, bool onNewLine);

	/**
	 * @brief makeFragmentNow creates a new fragment without text processing
	 * @param type is the type of needed fragment
	 * @param onNewLine if true creates the fragment on a new line
	 * @return the new created fragment
	 */
	Fragment * makeFragmentNow(FragmentTypes type, bool onNewLine);

private:
	// Properties
	Fragment * m_prev = nullptr;
	Fragment * m_next = nullptr;
	Line *     m_line = nullptr;

	uint8_t m_spaces = 0;
	uint8_t m_glyphs = 0;

	// fields
	QStaticText * cache = nullptr;
	QString       content;
};



}  // namespace icL::editor

#endif  // icL_editor_Fragment
