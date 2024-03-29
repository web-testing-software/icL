#ifndef icL_editor_Line
#define icL_editor_Line

#include <QString>



class QTextStream;
class QStaticText;
class QPainter;

namespace icL::editor {

class Fragment;
class Logic;
class Alpha;

/**
 * @brief The Line class describes a line of text
 */
class Line
{
public:
    explicit Line(Logic * parent = nullptr, bool isNew = true);

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
     * @brief nextDisplay gets next line to draw on display
     * @return the next line to display
     */
    Line * nextDisplay() const;

    /**
     * @brief prev gets the previous line
     * @return the previous line
     */
    Line * prev() const;

    /**
     * @brief prevDisplay gets previous line to draw on display
     * @return the previous line to display
     */
    Line * prevDisplay() const;

    /**
     * @brief length gets the length of the line
     * @return the lenght of the line
     */
    int length() const;

    /**
     * @brief beginPos is the begin position of the line
     * @return the begin position of text fragment
     */
    int beginPos() const;

    /**
     * @brief lineNumber return the line number
     * @return the number of line
     */
    int lineNumber() const;

    /**
     * @brief visible gets the visible state of line
     * @return true if line is visible, otherwise false
     */
    bool visible() const;

    /**
     * @brief hasBreakPoint gets the breaking property of line
     * @return true if need to break, otherwise false
     */
    bool hasBreakPoint() const;

    /**
     * @brief getText gets the text of line by concatenation all fragments
     * @return the text of line
     */
    const QString & getText(bool force = false);

    /**
     * @brief isChanged gets the changed state
     * @return true if is changed, otherwise false
     */
    bool isChanged();

    /**
     * @brief wasChanged gets the edited state
     * @return true if line was changed and saved, otherwise false
     */
    bool wasChanged();

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
     * @brief getCache returns the cache of line number
     * @return the pointer to cache of line number
     */
    QStaticText * getCache();

    /**
     * @brief isNew defines if this line is a new line
     * @return true if this is a new line, otherwise false
     */
    bool isNew();

    /**
     * @brief isPhantom defines if this line is a phantom line
     * @return true if this is a phantom line, otherwise false
     */
    bool isPhantom();

    /**
     * @brief isSelected defines if this line is phantom selected line
     * @return true if this line is phantom and selected, otherwise false
     */
    bool isSelected();

    /**
     * @brief hasPhantoms defines if this line contains phantoms lines
     * @return true if this line has some phantoms, otherwise false
     */
    bool hasPhantoms();

    /**
     * @brief getLastPhantom gets the last phantom of this line
     * @return the last phantom of this line
     */
    Line * getLastPhantom();

    /**
     * @brief lastY get the cached y coord
     * @return the last y coord of line drawing
     */
    int lastY();

public:
    /**
     * @brief updateLength recalc the length of line
     */
    void updateLength();

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
    void setBeginPos(int beginPos);

    /**
     * @brief setLineNumber changes the number of line
     * @param lineNumber is the new line number
     */
    void setLineNumber(int lineNumber);

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
     * @brief setLastY set the y coord of drawing
     * @param lastY is the value to cache
     */
    void setLastY(int lastY);

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
    int charsNumberInLineNumber();

    /**
     * @brief makePhantom makes this line phantom
     */
    void makePhantom();

    /**
     * @brief restorePhantom restores this line to normal state
     */
    void restorePhantom();

    /**
     * @brief dropPhantom removes the line definitely
     */
    void dropPhantom();

    /**
     * @brief showPhantoms enables/disamles the show of phantoms to screen
     */
    void showPhantoms(bool show = true);

    /**
     * @brief replaceContents replaces the content of line
     * @param content is the new content of line
     */
    void replaceContents(const QString & content);

    /**
     * @brief deleteNow deletes the lines now
     */
    void deleteNow();

    /**
     * @brief rawDropBegin drop drop the symbols on left of the 'pos'th char
     * @param pos the position of first undeleted char
     */
    void rawDropBegin(int pos);

    /**
     * @brief rawDropEnd drop the symbols on right of the 'pos'th character
     * inluding it
     * @param pos the position of first deleted symbol
     */
    void rawDropEnd(int pos);

private:
    // Properties

    /// @brief m_first is the first fragment in this line
    Fragment * m_first = nullptr;

    /// @brief m_next is the next line of text
    Line * m_next = nullptr;

    /// @brief m_prev is the previos line of text
    Line * m_prev = nullptr;

    /// @brief m_length is the number of symbols in this line
    int m_length = 0;

    /// @brief the absolute position of line begin in document
    int m_beginPos = 0;

    /// @brief the number of line in document
    int m_lineNumber = 0;

    /// @brief the visibility of line in editor
    bool m_visible = false;

    // fields

    /// @brief The line has unsaved chaghes
    bool m_isChanged = false;

    /// @brief the line was changed and saved
    bool m_wasChanged = false;

    /// @brief The line was added in edit time
    bool m_isNew = false;

    /// @brief Shows the phantom lines after this line
    bool m_showPhantom = false;

    /// @brief This line is a phontom line
    bool m_isPhantom = false;

    /// @brief this line is a phantom selected line
    bool m_isSelected = false;

    /// @brief The first phontom line after this line
    Line * phantom = nullptr;

    /// @brief Text content of the line
    QString content;

    /// @brief The editor which contains this line
    Logic * m_parent;

    /// @brief cache is the geometry of line number
    QStaticText * cache = nullptr;

    /// @brief The number of chars in line number
    int m_charsNumberInLineNumber = 0;

    /// @brief lastY is used for mouse interaction
    int m_lastY = 0;

    /// @brief This line has a break point
    bool m_hasBreakPoint = false;
};

}  // namespace icL::editor

#endif  // icL_editor_Line
