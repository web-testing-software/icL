#ifndef icL_look_EditorStyle
#define icL_look_EditorStyle

#include <QFont>
#include <QObject>



namespace icL::editor {
class StyleProxy;
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

	// clang-format off
	Q_PROPERTY(int charW READ charW WRITE setCharW NOTIFY charWChanged)
	Q_PROPERTY(int charH READ charH WRITE setCharH NOTIFY charHChanged)
	Q_PROPERTY(int fontS READ fontS WRITE setFontS NOTIFY fontSChanged)
	Q_PROPERTY(int lineS READ lineS WRITE setLineS NOTIFY lineSChanged)

	Q_PROPERTY(int   tabSize READ tabSize  WRITE setTabSize  NOTIFY tabSizeChanged)
	Q_PROPERTY(bool saveTabs READ saveTabs WRITE setSaveTabs NOTIFY saveTabsChanged)

	Q_PROPERTY(int  changePadding READ changePadding  WRITE setChangePadding  NOTIFY changePaddingChanged)
	Q_PROPERTY(int newLinePadding READ newLinePadding WRITE setNewLinePadding NOTIFY newLinePaddingChanged)
	Q_PROPERTY(int    changeWidth READ changeWidth    WRITE setChangeWidth    NOTIFY changeWidthChanged)
	Q_PROPERTY(int phanthomHeight READ phanthomHeight WRITE setPhanthomHeight NOTIFY phanthomHeightChanged)
	// clang-format on

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
	 * @brief tabSize is the size of tab in spaces
	 * @return the size of tab in spaces
	 */
	int tabSize() const;

	/**
	 * @brief saveTabs decides to save tabs or spaces
	 * @return true if need to save tabs, otherwise false
	 */
	bool saveTabs() const;

	/**
	 * @brief font is the base font for editor
	 * @return the base font
	 */
	const QFont & font();

	/**
	 * @brief changePadding padding for change lines
	 * @return the padding for change lines
	 */
	int changePadding() const;

	/**
	 * @brief newLinePadding the padding of new lines
	 * @return the padding for new lines
	 */
	int newLinePadding() const;

	/**
	 * @brief changeWidth the width of change indicator
	 * @return the width for change indicator
	 */
	int changeWidth() const;

	/**
	 * @brief phanthomHeight the height of phantom lines
	 * @return the height for phantom lines
	 */
	int phanthomHeight() const;

signals:
	void charWChanged(int charW);
	void charHChanged(int charH);
	void fontSChanged(int fontS);
	void lineSChanged(int lineS);
	void tabSizeChanged(int tabSize);
	void saveTabsChanged(bool saveTabs);
	void changePaddingChanged(int changePadding);
	void newLinePaddingChanged(int newLinePadding);
	void changeWidthChanged(int changeWidth);
	void phanthomHeightChanged(int phanthomHeight);

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

	/**
	 * @brief setTabSize changes the size of tabs
	 * @param tabSize is the new size of tab in spaces
	 */
	void setTabSize(int tabSize);

	/**
	 * @brief setSaveTabs changes the save mode
	 * @param saveTabs if true the spaces will be repalced with tabs
	 */
	void setSaveTabs(bool saveTabs);

	/**
	 * @brief setChangePadding sets the padding of changes indicators
	 * @param changePadding is the new padding for changes indicators
	 */
	void setChangePadding(int changePadding);

	/**
	 * @brief setNewLinePadding sets the padding of new lines indicators
	 * @param newLinePadding is the padding for new lines indicators
	 */
	void setNewLinePadding(int newLinePadding);

	/**
	 * @brief setChangeWidth sets the width of change indicators
	 * @param changeWidth is the new width for change indicators
	 */
	void setChangeWidth(int changeWidth);

	/**
	 * @brief setPhanthomHeight sets the height of phantom indicators
	 * @param phanthomHeight is the new height for phantom indicators
	 */
	void setPhanthomHeight(int phanthomHeight);

	// Get the private properties without getters
	// This fixes dependency beetwen QML plugins
	// Never change the values, just read
	friend class editor::StyleProxy;

private:
	/**
	 * @brief fixFont fix font on font size changes
	 */
	void fixFont();

	// Properties
	int m_charW = 1;
	int m_charH = 1;
	int m_fontS = 1;
	int m_lineS = 1;

	int m_changePadding  = 0;
	int m_newLinePadding = 0;
	int m_changeWidth    = 0;
	int m_phanthomHeight = 0;

	int  m_tabSize  = 3;
	bool m_saveTabs = true;

	// fields

	/// @brief the style has changes of change indicators
	bool hasChangeChanges = true;

	/// @brief m_divLineSBy2 is the line spacing divided by 2
	int m_divLineSBy2 = 1;

	/// @brief m_fullLineH is the full height of line (text + spacing)
	int m_fullLineH = 1;

	/// @brief font is the standart font object
	QFont m_font;
};

}  // namespace icL::look

#endif  // icL_look_EditorStyle
