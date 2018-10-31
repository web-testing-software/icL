#ifndef LINENUMBERS_H
#define LINENUMBERS_H

#include <QQuickPaintedItem>

namespace icL::editor {

class EditorInternal;

class LineNumbers : public QQuickPaintedItem
{
	Q_OBJECT

public:
	explicit LineNumbers(QQuickItem * parent = nullptr);

signals:

public slots:
	/**
	 * @brief setEditor set up the line panel
	 * @param editor is the editor of lines number panel
	 */
	void setEditor(EditorInternal * editor);

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
	EditorInternal * m_editor;
};

}  // namespace icL::editor

#endif  // LINENUMBERS_H
