#ifndef EDITOR_H
#define EDITOR_H

#include <QQuickPaintedItem>

namespace icL::look {
class Editor;
}

/**
 * The icL.editor namespace defines a own QPlainText editor
 */
namespace icL::editor {

/**
 * @brief The Editor class is class which will be on display
 */
class Editor : public QQuickPaintedItem
{
	Q_OBJECT

	Q_PROPERTY(look::Editor * look READ look WRITE setLook NOTIFY lookChanged)

	Q_PROPERTY(int charW READ charW WRITE setCharW NOTIFY charWChanged)
	Q_PROPERTY(int charH READ charH WRITE setCharH NOTIFY charHChanged)
	Q_PROPERTY(int fontS READ fontS WRITE setFontS NOTIFY fontSChanged)

public:
	/**
	 * @brief Editor is the default constructor
	 * @param parent is the default QObject arg
	 */
	Editor(QQuickItem * parent = nullptr);

	/**
	 * @brief look is the look of this editor
	 * @return the look for this editor
	 */
	look::Editor * look() const;

	/**
	 * @brief charW is the width of char in editor
	 * @return the width of char in editor
	 */
	int charW() const;

	/**
	 * @brief charH is the height of line in editor
	 * @return the height of line in editor
	 */
	int charH() const;

	/**
	 * @brief fontS is the size of font
	 * @return the size of font
	 */
	int fontS() const;

signals:
	void lookChanged(look::Editor * look);
	void charWChanged(int charW);
	void charHChanged(int charH);
	void fontSChanged(int fontS);

public slots:
	/**
	 * @brief setLook changes the look of editor
	 * @param look is the new look for editor
	 */
	void setLook(look::Editor * look);

	/**
	 * @brief setCharW changes the width of char
	 * @param charW is the new width of char
	 */
	void setCharW(int charW);

	/**
	 * @brief setCharH chages the height of line
	 * @param charH is the new height of line
	 */
	void setCharH(int charH);

	/**
	 * @brief setFontS changes the font size
	 * @param fontS is the new font size
	 */
	void setFontS(int fontS);

	/**
	 * @brief resize handles the width and height changes
	 */
	void resize();

	// QQuickPaintedItem interface
public:
	void paint(QPainter * painter) override;

private:
	// Properties

	look::Editor * m_look = nullptr;

	int m_charW;
	int m_charH;
	int m_fontS;

	// Drawing cache
	QRect lineNumbers;
	QRect textArea;
};

}  // namespace icL::editor

#endif  // EDITOR_H
