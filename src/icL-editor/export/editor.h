#ifndef icL_editor_Editor
#define icL_editor_Editor

#include <QQuickPaintedItem>


namespace look {
class EditorStyle;
}

namespace icL::editor {

class Selection;
class Line;

class Editor : public QQuickPaintedItem
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::look::EditorStyle*   style READ style        WRITE setStyle        NOTIFY styleChanged)
	Q_PROPERTY(icL::editor::Selection*    main READ main         NOTIFY mainChanged)
	Q_PROPERTY(icL::editor::Line*        first READ first        WRITE setFirst        NOTIFY firstChanged)
	Q_PROPERTY(icL::editor::Line*      current READ current      WRITE setCurrent      NOTIFY currentChanged)
	Q_PROPERTY(icL::editor::Line* firstVisible READ firstVisible WRITE setFirstVisible NOTIFY firstVisibleChanged)
	Q_PROPERTY(icL::editor::Line*  lastVisible READ lastVisible  WRITE setLastVisible  NOTIFY lastVisibleChanged)
	// clang-format on

public:
	Editor(QQuickItem * parent);

	/**
	 * @brief style is the style of all editors
	 * @return the style for all editrs
	 */
	look::EditorStyle * style() const;

	/**
	 * @brief main is the main selection
	 * @return the main selection
	 */
	Selection * main() const;

	/**
	 * @brief first is the first line of text
	 * @return the first line of text
	 */
	Line * first() const;

	/**
	 * @brief current is the current line of text
	 * @return the current line of text
	 */
	Line * current() const;

	/**
	 * @brief firstVisible is the first visible line
	 * @return the first visible line
	 */
	Line * firstVisible() const;

	/**
	 * @brief lastVisible is the last visible line
	 * @return th elast visible line
	 */
	Line * lastVisible() const;

signals:
	void styleChanged(look::EditorStyle * style);
	void mainChanged(Selection * main);
	void firstChanged(Line * first);
	void currentChanged(Line * current);
	void firstVisibleChanged(Line * firstVisible);
	void lastVisibleChanged(Line * lastVisible);

public slots:
	/**
	 * @brief setStyle sets the style of editor
	 * @param style is the new style for editor
	 */
	void setStyle(look::EditorStyle * style);

	/**
	 * @brief setFirst changes the pointer to the first line
	 * @param first is the new first line
	 */
	void setFirst(Line * first);

	/**
	 * @brief setCurrent changes the pointer to the current line
	 * @param current is the new current line
	 */
	void setCurrent(Line * current);

	/**
	 * @brief setFirstVisible changes the pointer to the fisrt visible line
	 * @param firstVisible is the new first visible line
	 */
	void setFirstVisible(Line * firstVisible);

	/**
	 * @brief setLastVisible changes the pointer to the last visible line
	 * @param lastVisible is the new last visible line
	 */
	void setLastVisible(Line * lastVisible);

private:
	look::EditorStyle * m_style = nullptr;

	Selection * m_main = nullptr;

	Line * m_first        = nullptr;
	Line * m_current      = nullptr;
	Line * m_firstVisible = nullptr;
	Line * m_lastVisible  = nullptr;
};

}  // namespace icL::editor

#endif  // icL_editor_Editor
