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
	Q_PROPERTY(icL::look::EditorStyle*   style READ style WRITE setStyle NOTIFY styleChanged)
	Q_PROPERTY(icL::look::Chars*         chars READ chars WRITE setChars NOTIFY charsChanged)
	Q_PROPERTY(icL::editor::LineNumbers* lineN READ lineN WRITE setLineN NOTIFY lineNChanged)

	Q_PROPERTY(int lnWidth READ lnWidth NOTIFY lnWidthChanged)
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
	 * @brief lnWidth is the width of line number bar
	 * @return
	 */
	int lnWidth() const;

	/**
	 * @brief makeCursorOpaque set the opacity of cursor to 1
	 */
	void makeCursorOpaque();

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
	void lineNChanged(LineNumbers * lineN);
	/// @brief elude QML warning
	void lnWidthChanged(int lnWidth);

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
	 * @brief setLineN sets the lines numbers widget
	 * @param lineN is the lines numbers widget
	 */
	void setLineN(LineNumbers * lineN);

private slots:
	/**
	 * @brief updateBackgroundGeometry updatates the background geometry, which
	 * consist from 2 rectangles (line number area and content area)
	 */
	void updateBackgroundGeometry();

private:
	/**
	 * @brief drawLineNumbers is the 1st step of drawing (after display clear)
	 *
	 * It draws the line number of left side for each visible line.
	 */
	void drawLineNumbers(QPainter * painter);

	/**
	 * @brief drawBreakPoints is the 2nd step of drawing
	 *
	 * Draw each visible breakpoint over the existing line numbers.
	 */
	void drawBreakPoints(QPainter * painter);

	/**
	 * @brief drawLine draws a line with a specified format
	 * @param painter is the painter to use
	 * @param line is the line to draw
	 * @param format is the format to use
	 */
	void drawLine(QPainter * painter, Line * line, look::LineFormat & format);

	/**
	 * @brief drawCurrentLine is the 3rd step of drawing
	 *
	 * Draw the current line number and background over the existing
	 * lines numbers and breakpoints
	 */
	void drawCurrentLine(QPainter * painter);

	/**
	 * @brief drawDebugLine is the 4th step of drawing
	 *
	 * Draw the debug line over all existing content.
	 */
	void drawDebugLine(QPainter * painter);

	/**
	 * @brief setUpClipArea restricts drawing on line number area
	 */
	void setUpClipArea(QPainter * painter);

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

	/**
	 * @brief transition make a special transition for opacity of cursor
	 * @param x - is the linear interpoleted value
	 * @return the smooth interpolated fixed value
	 */
	qreal transition(qreal x);

	/**
	 * @brief drawCursor draws the text cursor
	 */
	void drawCursor(QPainter * painter);

protected:
	// properties
	/// @brief the pointer to look of editor characters
	look::Chars * m_chars = nullptr;

	/// @brief the pointer to line numbers widget (set width on geometry update)
	LineNumbers * m_lineN = nullptr;

	// fields
	/// @brief the rect of line numbers widget
	QRect lineNumberArea;

	/// @brief is the padding of left side (exclude area under line numbers)
	int leftPadding;

	/// @brief The proxy to style value from Look QML plugin
	StyleProxy * m_proxy;

	/// @brief The right line for line numbers align
	int lineNumberRight{};

	/// @brief number of visible chars in line
	int visibleChars{};

	/// @brief number of visible lines in editor
	int visibleLines{};

	/// @brief the arrow for hightlight current line
	QPolygon leftArrow;

	/// @brief used to highlight current line
	QRect lineRect;

	/// @brief timer for create the cursor blinding
	QTime cursorTimer;

	/// @brief the current animation direction
	bool cursorIsHidding = false;

	/// @brief the current x scroll position
	uint8_t xScroll = 0;
};

}  // namespace icL::editor

#endif  // icL_editor_Drawing
