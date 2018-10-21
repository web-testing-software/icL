#ifndef icL_editor_StyleProxy
#define icL_editor_StyleProxy

namespace icL::look {
class EditorStyle;
}

namespace icL::editor {

/**
 * @brief The StyleProxy class make aviable style data from Look QML Plugin
 */
class StyleProxy
{
public:
	StyleProxy();

	/**
	 * @brief getStyle gets the style pointer
	 * @return the pointer to the style
	 */
	look::EditorStyle * style();

	/**
	 * @brief setStyle sets the pointer to style
	 * @param style is the pointer to style
	 */
	void setStyle(look::EditorStyle * style);

	/**
	 * @brief charW is the width of char in editor
	 * @return the width of chars in editor
	 */
	int charW();

	/**
	 * @brief charH is the height of chars in editor
	 * @return the height of chars in editor
	 */
	int charH();

	/**
	 * @brief fontS is the font size of the editor
	 * @return the size of font
	 */
	int fontS();

	/**
	 * @brief lineS is the line spacing
	 * @return the spaces beetwen lines
	 */
	int lineS();

	/**
	 * @brief tabSize is the size of tabs in spaces
	 * @return the size of tabs in pixels
	 */
	int tabSize();

	/**
	 * @brief saveTabs decides if need to save tabs to disk
	 * @return true if need to save tabs, otherwise false
	 */
	bool saveTabs();

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

private:
	look::EditorStyle * m_style;
};

}  // namespace icL::editor

#endif  // icL_editor_StyleProxy
