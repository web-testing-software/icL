#ifndef icL_look_EditorStyle
#define icL_look_EditorStyle

#include <QFont>
#include <QObject>



namespace icL::editor {
class Drawing;
}

/**
 * The icL.editor namespace defines a own QPlainText editor
 */
namespace icL::look {

/**
 * @brief The Editor class is class which will be on display
 */
class EditorStyle : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int charW READ charW WRITE setCharW NOTIFY charWChanged)
	Q_PROPERTY(int charH READ charH WRITE setCharH NOTIFY charHChanged)
	Q_PROPERTY(int fontS READ fontS WRITE setFontS NOTIFY fontSChanged)
	Q_PROPERTY(int lineS READ lineS WRITE setLineS NOTIFY lineSChanged)

public:
	/**
	 * @brief Editor is the default constructor
	 * @param parent is the default QObject arg
	 */
	EditorStyle(QObject * parent = nullptr);

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

	/**
	 * @brief lineS is the line spacing
	 * @return the spacing of line
	 */
	int lineS() const;

	/**
	 * @brief divLineSBy2 is the line spacing divided by 2
	 * @return the line spacing divided by 2
	 */
	int divLineSBy2() const;

	/**
	 * @brief fullLineH is the full line height
	 * @return the full height of line
	 */
	int fullLineH() const;

	/**
	 * @brief font is the base font for editor
	 * @return the base font
	 */
	const QFont & font();

signals:
	void charWChanged(int charW);
	void charHChanged(int charH);
	void fontSChanged(int fontS);
	void lineSChanged(int lineS);

public slots:
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
	 * @brief setLineS changes the current line spacing
	 * @param lineS is the new line spacing
	 */
	void setLineS(int lineS);

	// Get the private properties without getters
	// This fixes dependency beetwen QML plugins
	// Never change the values, just read
	friend class editor::Drawing;

private:
	/**
	 * @brief fixFont fix font on font size changes
	 */
	void fixFont();

	// Properties
	int m_charW = 10;
	int m_charH = 20;
	int m_fontS = 10;
	int m_lineS = 4;

	// fields

	/// @brief m_divLineSBy2 is the line spacing divided by 2
	int m_divLineSBy2 = 2;

	/// @brief m_fullLineH is the full height of line (text + spacing)
	int m_fullLineH = 14;

	/// @brief font is the standart font object
	QFont m_font;
};

}  // namespace icL::editor

#endif  // icL_look_EditorStyle
