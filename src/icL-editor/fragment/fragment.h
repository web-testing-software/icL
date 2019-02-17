#ifndef icL_editor_Fragment
#define icL_editor_Fragment

#include <QString>



namespace icL::look {
struct TextCharFormat;
}

class QStaticText;

namespace icL::editor {

class Line;
class EditorInternal;
class Cursor;

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
    bool onNextLine = false;
};

/**
 * @brief The FragmentTypes enum describes the posible fragment types
 */
enum class FragmentTypes { Fragment, Word, String, Bracket };

/**
 * @brief The Fragment class decribes any fragment of text
 */
class Fragment
{
public:
    explicit Fragment(Line * parent = nullptr);

    virtual ~Fragment();

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
     * @brief getText gets the text of the fragment
     * @param begin is the begin position of interval
     * @param end is the end position of interval
     * @return the reference to needed text fragment
     */
    const QString getText(int begin = 0, int end = -1);

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
    Fragment * drop(Cursor * cursor, int begin = 0, int end = -1);

    /**
     * @brief insert inserts a text to needed position
     * @param pos is the position to insert in
     * @param text is the text to insert
     */
    Fragment * insert(
      Cursor * begin, Cursor * end, int pos, const QString & text);

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

    /**
     * @brief format returns the format to draw this text fragment
     * @return the format to draw this text fragment
     */
    virtual const look::TextCharFormat & format();

    /**
     * @brief isReadOnly protects to edit this text fragment
     * @return true if the protection is activated, otherwise false
     */
    bool isReadOnly();

    /**
     * @brief setReadOnly activates/deactivated fragment protection
     * @param value true - activates, false - deactivates
     */
    void setReadOnly(bool value);

    /**
     * @brief replaceContent replace all the content of this line
     * @param content is the new content of fragment
     */
    void replaceContent(const QString & content);

    /**
     * @brief rawInsert inserts data in fragment without modifications
     * @param cursor is the cursor which need to be updated
     * @param pos is the position of insertion
     * @param text is the text to insert
     */
    void rawInsert(Cursor * cursor, int pos, const QString & text);

    /**
     * @brief rawDrop removes the data in fragment
     * @param cursor is the cursor which need to be updated
     * @param begin is the begin position
     * @param end is the last cursor
     */
    void rawDrop(int begin = 0, int end = -1);

public:
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
    EditorInternal * getEditor();

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
    virtual Fragment * insertInSpaces(
      Cursor * begin, Cursor * end, int pos, const QString & text);

    /**
     * @brief insertAfterSpaces prepends glyphs to content
     * @param pos is the position of insertion
     * @param text is the text to insert
     */
    virtual Fragment * insertAfterSpaces(
      Cursor * begin, Cursor * end, const QString & text);

    /**
     * @brief insertInGlyphs inserts glyphs in content
     * @param pos is the position of insertion
     * @param text is the text to insert
     */
    virtual Fragment * insertInGlyphs(
      Cursor * begin, Cursor * end, int pos, const QString & text);

    /**
     * @brief insertAfterGlyphs appends glyphs after content
     * @param pos is the position of insertion
     * @param text is the text to insert
     */
    virtual Fragment * insertAfterGlyphs(
      Cursor * begin, Cursor * end, const QString & text);

    /**
     * @brief dropSpaces removes spaces
     * @param p1 is the index of first selected character
     * @param p2 is the index of last selected character
     */
    virtual Fragment * dropSpaces(Cursor * cursor, int p1, int p2);

    /**
     * @brief dropHead removes spaces and content glyphs
     * @param p1 is the index of first selected character
     * @param p2 is the index of last selected character
     */
    virtual Fragment * dropHead(Cursor * cursor, int p1, int p2);

    /**
     * @brief dropContent removes content fragment
     * @param p1 is the index of first selected character
     * @param p2 is the index of last selected character
     */
    virtual Fragment * dropContent(Cursor * cursor, int p1, int p2);

    /**
     * @brief dropTail removes the end of content
     * @param p1 is the index of first selected character
     * @param p2 is the index of last selected character
     */
    virtual Fragment * dropTail(Cursor * cursor, int p1, int p2);

    /**
     * @brief dropAllContent removes all content of the fragment
     * @param p1 is the index of first selected character
     * @param p2 is the index of last selected character
     */
    virtual Fragment * dropAllContent(Cursor * cursor, int p1);

protected:
    /**
     * @brief makeNewFragment creates a new fragment of text in editor
     * @param text is the text of the new fragment
     * @param onNewLine if true creates the fragment on a new line
     * @return the new created fragment
     */
    Fragment * makeNewFragment(
      Cursor * begin, Cursor * end, const QString & text, bool onNewLine);

    /**
     * @brief makeFragmentNow creates a new fragment without text processing
     * @param type is the type of needed fragment
     * @param onNewLine if true creates the fragment on a new line
     * @return the new created fragment
     */
    Fragment * makeFragmentNow(FragmentTypes type, bool onNewLine);

    /**
     * @brief ensurePrev ensure that this fragment has a previous fragment
     */
    void ensurePrev();

    /**
     * @brief moveNextBlockAfter move the next block from line
     * @param after the fragment in insert after it
     */
    void moveNextBlockAfter(Fragment * after);

    /**
     * @brief countSpaceAtBegin counts the spaces at the begin of text
     * @param text is the text to analize
     * @return the count of spaces at the begin
     */
    int countSpacesAtBegin(const QString & text);

    /**
     * @brief countSpacesAtEnd counts the spaces at the end of text
     * @param text is the text to analize
     * @return the count of spaces at the end
     */
    static int countSpacesAtEnd(const QString & text);

protected:
    // Properties

    /// @brief m_prev is the prevoius fragment is the same line
    Fragment * m_prev = nullptr;

    /// @brief m_next is the next fragment is the same line
    Fragment * m_next = nullptr;

    /// @brief m_line is the parent of fragment (a line of text)
    Line * m_line = nullptr;

    /// @brief m_spaces is the count of spaces before text
    uint8_t m_spaces = 0;

    /// @brief m_glyphs is the number of chars in text of fragment
    uint8_t m_glyphs = 0;

    // fields

    /// @brief cache is a pointer to the cached text geometry
    QStaticText * cache = nullptr;

    /// @brief text of this fragment
    QString content;

    /// @brief readOnly protects this field
    bool readOnly = false;
};



}  // namespace icL::editor

#endif  // icL_editor_Fragment
