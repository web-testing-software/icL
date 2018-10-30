#ifndef LINENUMBERS_H
#define LINENUMBERS_H

#include <QQuickPaintedItem>

namespace icL::editor {

class Drawing;

class LineNumbers : public QQuickPaintedItem
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Drawing * editor READ editor WRITE setEditor NOTIFY editorChanged)
	// clang-format on

public:
	explicit LineNumbers(QQuickItem * parent = nullptr);

	/**
	 * @brief editor is the editor for which we generate lines numbers panel
	 * @return the editor of lines numbers panel
	 */
	Drawing * editor() const;

signals:
	void editorChanged(Drawing * editor);

public slots:
	/**
	 * @brief setEditor set up the line panel
	 * @param editor is the editor of lines number panel
	 */
	void setEditor(Drawing * editor);

	// QQuickPaintedItem interface
public:
	void paint(QPainter * painter) override;

private:
	/**
	 * @brief drawBackground draws the background of line numbers panels
	 * @param painter is the painter to draw with
	 */
	void drawBackground(QPainter * painter);

	/**
	 * @brief drawText draws the text itself
	 * @param painter is the painter to draw with
	 */
	void drawText(QPainter * painter);

private:
	// Properties
	Drawing * m_editor;
};

}  // namespace icL::editor

#endif  // LINENUMBERS_H
