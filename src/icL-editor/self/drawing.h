#ifndef EDITORDRAWING_H
#define EDITORDRAWING_H

#include "logic.h"

#include <QObject>
#include <QPolygon>

namespace icL::look {
class EditorStyle;
class Chars;
}  // namespace icL::look

namespace icL::editor {

class Drawing : public Logic
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::look::EditorStyle* style READ style WRITE setStyle NOTIFY styleChanged)
	Q_PROPERTY(icL::look::Chars*       chars READ chars WRITE setChars NOTIFY charsChanged)
	// clang-format on

public:
	explicit Drawing(QQuickItem * parent = nullptr);

	/**
	 * @brief style is the style of all editors
	 * @return the style for all editrs
	 */
	look::EditorStyle * style() const;

	/**
	 * @brief chars is the look of chars in editor
	 * @return the style for chars in editor
	 */
	look::Chars * chars() const;

	// QQuickPaintedItem interface
public:
	void paint(QPainter * painter) override;

signals:
	void styleChanged(look::EditorStyle * style);

	void charsChanged(look::Chars * chars);

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
	void drawLineNumbers(QPainter *painter);

	/**
	 * @brief drawBreakPoints is the 2nd step of drawing
	 *
	 * Draw each visible breakpoint over the existing line numbers.
	 */
	void drawBreakPoints(QPainter *painter);

	/**
	 * @brief drawCurrentLine is the 3rd step of drawing
	 *
	 * Draw the current line number and background over the existing
	 * lines numbers and breakpoints
	 */
	void drawCurrentLine();

	/**
	 * @brief drawDebugLine is the 4th step of drawing
	 *
	 * Draw the debug line over all existing content.
	 */
	void drawDebugLine();

	/**
	 * @brief setUpClipArea restricts drawing on line number area
	 */
	void setUpClipArea();

	/**
	 * @brief drawSelection is the 5th step of drawing
	 *
	 * Draws the selection over the all line hightlights.
	 */
	void drawSelection();

	/**
	 * @brief drawContent is the 6th step of drawing
	 *
	 * Draw the text of editor itself, over all selection all line hightlights.
	 */
	void drawContent();

protected:
	// properties
	look::EditorStyle * m_style = nullptr;
	look::Chars *       m_chars = nullptr;


	// fields
	QRect lineNumberArea;
	QRect contentArea;
	QRect scissorsArea;

	/// The right line for line numbers align
	int lineNumberRight;

	/// @brief number of visible chars in line
	int visibleChars;

	/// @brief number of visible lines in editor
	int visibleLines;

	/// @brief the arrow for hightlight current line
	QPolygon leftArrow;

	/// @brief used to highlight current line
	QRect lineRect;
};

}  // namespace icL::editor

#endif  // EDITORDRAWING_H
