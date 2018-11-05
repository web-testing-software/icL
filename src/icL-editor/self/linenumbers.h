#ifndef LINENUMBERS_H
#define LINENUMBERS_H

#include <QQuickPaintedItem>
#include <QStaticText>



namespace icL::editor {

class EditorInternal;

/**
 * @brief The LineNumbers class is a widget which displays the numbers of lines
 */
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
	void setEditor(icL::editor::EditorInternal * editor);

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

	/**
	 * @brief drawChanges draws changes indicators
	 * @param painter is the painter to draw with
	 */
	void drawChanges(QPainter * painter);

	/**
	 * @brief drawChanges draws changes indicators
	 * @param painter is the painter to draw with
	 */
	void updateGeometry();

private:
	// Properties
	EditorInternal * m_editor;

	/// @brief symbol used to mark edited lines
	QStaticText edited{"*"};

	/// @brief symbol used to mark new lines
	QStaticText newLine{"+"};

	/// @brief symbol used to mark phantom lines
	QStaticText phantom{"-"};

	/// @brief symbol used to mark phantom selected lines
	QStaticText phantomS{"#"};
};

}  // namespace icL::editor

#endif  // LINENUMBERS_H
