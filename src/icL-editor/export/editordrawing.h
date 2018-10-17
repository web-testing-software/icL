#ifndef EDITORDRAWING_H
#define EDITORDRAWING_H

#include "editor.h"

#include <QObject>

namespace icL::editor {

class EditorDrawing : public Editor
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::look::EditorStyle* style READ style WRITE setStyle NOTIFY styleChanged)
	// clang-format on

public:
	explicit EditorDrawing(QQuickItem *parent = nullptr);

	/**
	 * @brief style is the style of all editors
	 * @return the style for all editrs
	 */
	look::EditorStyle * style() const;


	// QQuickPaintedItem interface
public:
	void paint(QPainter *painter) override;

signals:
	void styleChanged(look::EditorStyle * style);

public slots:
	/**
	 * @brief setStyle sets the style of editor
	 * @param style is the new style for editor
	 */
	void setStyle(look::EditorStyle * style);

private slots:
	/**
	 * @brief updateBackgroundGeometry updatates the background geometry, which
	 * consist from 2 rectangles (line number area and content area)
	 */
	void updateBackgroundGeometry();

protected:
	// properties
	look::EditorStyle * m_style = nullptr;

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
};

} // namespace

#endif // EDITORDRAWING_H
