#ifndef icL_editor_Drawing
#define icL_editor_Drawing

#include "logic.h"

#include <QDateTime>
#include <QObject>
#include <QPolygon>



namespace icL::look {
class EditorStyle;
class Chars;
struct LineFormat;
class ScrollBar;
}  // namespace icL::look

namespace icL::editor {

class StyleProxy;
class OpacityMask;
class CursorsArea;

/**
 * @brief The Drawing class draws the content of editor
 */
class Drawing : public Logic
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(icL::look::EditorStyle*   style READ style     WRITE setStyle     NOTIFY styleChanged)
    Q_PROPERTY(icL::look::Chars*         chars READ chars     WRITE setChars     NOTIFY charsChanged)
    Q_PROPERTY(icL::look::ScrollBar* scrollBar READ scrollBar WRITE setScrollBar NOTIFY scrollBarChanged)
    Q_PROPERTY(icL::editor::LineNumbers* lineN READ lineN     WRITE setLineN     NOTIFY lineNChanged)

    Q_PROPERTY(int    lnWidth READ lnWidth    NOTIFY lnWidthChanged)
    Q_PROPERTY(int linesCount READ linesCount NOTIFY linesCountChanged)

    Q_PROPERTY(int  charsInLine READ charsInLine   WRITE setCharsInLine  NOTIFY charsInLineChanged)
    Q_PROPERTY(int visbileLines READ dVisbileLines WRITE setVisbileLines NOTIFY visbileLinesChanged)
    Q_PROPERTY(int  firstLineNr READ dFirstLineNr  NOTIFY firstLineNrChanged)
    Q_PROPERTY(int  firstCharNr READ dFirstCharNr  NOTIFY firstCharNrChanged)
    // clang-format on

public:
    explicit Drawing(QQuickItem * parent = nullptr);

    /**
     * @brief style is the style of all editors
     * @return the style for all editrs
     */
    look::EditorStyle * style() const;

    /**
     * @brief proxy is the proxy of style data over QML Plugins
     * @return the proxy to access data from Look QML Plugin
     */
    StyleProxy * proxy();

    /**
     * @brief lineN is the lines numbers area widget
     * @return the lines numbers area widget
     */
    LineNumbers * lineN() const;

    /**
     * @brief chars is the look of chars in editor
     * @return the style for chars in editor
     */
    look::Chars * chars() const;

    /**
     * @brief scrollBar is the look of scroll bars
     * @return the look for scroll bars
     */
    icL::look::ScrollBar * scrollBar() const;

    /**
     * @brief lnWidth is the width of line number bar
     * @return the width of lines numbers area
     */
    int lnWidth() const;

    /**
     * @brief linesCount gets the number of lines
     * @return the number of lines in editor
     */
    int linesCount() const;

    /**
     * @brief charsInLine is the number of visible chars in line
     * @return the number of  visible chars in line
     */
    int charsInLine() const;

    /**
     * @brief visbileLines is the number of visible lines
     * @return the number of visible lines
     */
    int dVisbileLines() const override;

    /**
     * @brief firstLineNr is the first visible line number
     * @return the number of first visible line
     */
    int dFirstLineNr() const;

    /**
     * @brief firstCharNr is the number of first visible char
     * @return the number of first visible char
     */
    int dFirstCharNr() const;

    /**
     * The drawing of line number was a part of Drawing class, now it's extern
     */
    friend class icL::editor::LineNumbers;
    friend class icL::editor::OpacityMask;
    friend class icL::editor::CursorsArea;

    // QQuickPaintedItem interface
public:
    void paint(QPainter * painter) override;

signals:
    /// @brief elude QML warning
    void styleChanged(look::EditorStyle * style);
    /// @brief elude QML warning
    void charsChanged(look::Chars * chars);
    /// @brief elude QML warning
    void scrollBarChanged(icL::look::ScrollBar * scrollBar);
    /// @brief elude QML warning
    void lineNChanged(LineNumbers * lineN);
    /// @brief elude QML warning
    void lnWidthChanged(int lnWidth);
    /// @brief elude QML warning
    void firstCharNrChanged(int dFirstCharNr);
    /// @brief elude QML warning
    void charsInLineChanged(int charsInLine);
    /// @brief elude QML warning
    void visbileLinesChanged(int dVisbileLines);

    /**
     * @brief makeCursorOpaque set the opacity of cursor to 1
     */
    void makeCursorOpaque();

public slots:
    /**
     * @brief setStyle sets the style of editor
     * @param style is the new style for editor
     */
    void setStyle(look::EditorStyle * style);

    /**
     * @brief setChars changes the look of chars
     * @param chars is the new look for chars
     */
    void setChars(look::Chars * chars);

    /**
     * @brief setScrollBar changes the look of scroll bars
     * @param scrollBar is the new look for scroll bars
     */
    void setScrollBar(icL::look::ScrollBar * scrollBar);

    /**
     * @brief setLineN sets the lines numbers widget
     * @param lineN is the lines numbers widget
     */
    void setLineN(LineNumbers * lineN);

    /**
     * @brief setCharsInLine sets the number of visible chars in line
     * @param charsInLine the number of chars calculated in QML
     */
    void setCharsInLine(int charsInLine);

    /**
     * @brief setVisbileLines sets the number of visible lines
     * @param visbileLines the number of lines calculated in QML
     */
    void setVisbileLines(int dVisbileLines);

private slots:
    /**
     * @brief updateBackgroundGeometry updatates the background geometry, which
     * consist from 2 rectangles (line number area and content area)
     */
    void dUpdateBackgroundGeometry() override;

private:
    /**
     * @brief drawBreakPoints is the 2nd step of drawing
     *
     * Draw each visible breakpoint over the existing line numbers.
     */
    void drawBreakPoints(QPainter * painter);

    /**
     * @brief drawCurrentLine is the 3rd step of drawing
     *
     * Draws the current line number and background over the existing
     * lines numbers and breakpoints
     */
    void drawCurrentLine(QPainter * painter);

    /**
     * @brief drawPhantoms is the 4th step of drawing
     *
     * Draws the background of phantom lines
     */
    void drawPhantoms(QPainter * painter);

    /**
     * @brief drawSelection is the 5th step of drawing
     *
     * Draws the selection over the all line hightlights.
     */
    void drawSelection(QPainter * painter, Selection * selection);

    /**
     * @brief drawContent is the 6th step of drawing
     *
     * Draw the text of editor itself, over all selection all line hightlights.
     */
    void drawContent(QPainter * painter);

protected:
    // properties
    /// @brief the pointer to look of editor characters
    look::Chars * m_chars = nullptr;

    /// @brief the pointer to look of scroll bars
    icL::look::ScrollBar * m_scrollBar = nullptr;

    /// @brief the pointer to line numbers widget (set width on geometry update)
    LineNumbers * m_lineN = nullptr;

    // fields
    /// @brief the rect of line numbers widget
    QRect lineNumberArea;

    /// @brief is the padding of left side (exclude area under line numbers)
    int m_leftPadding = 0;

    /// @brief The proxy to style value from Look QML plugin
    StyleProxy * m_proxy;

    /// @brief The right line for line numbers align
    int lineNumberRight = 0;

    /// @brief number of visible chars in line
    int m_visibleChars = 0;

    /// @brief number of visible lines in editor
    int m_visibleLines = 0;

    /// @brief the arrow for hightlight current line
    QPolygon leftArrow;

    /// @brief the rect to highlight phantom lines
    QRect leftRect;

    /// @brief used to highlight current line
    QRect lineRect;

    /// @brief the current x scroll position
    uint8_t xScroll = 0;
};

}  // namespace icL::editor

#endif  // icL_editor_Drawing
