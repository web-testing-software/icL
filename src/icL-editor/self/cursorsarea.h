#ifndef icL_editor_CursorsArea
#define icL_editor_CursorsArea

#include "../private/alpha.h"

#include <QQuickItem>

class QSGOpacityNode;

namespace icL::editor {

class EditorInternal;

class CursorsArea : public QQuickItem
{
	Q_OBJECT

	Q_PROPERTY(int cursorW READ cursorW WRITE setCursorW NOTIFY cursorWChanged)

public:
	explicit CursorsArea(QQuickItem * parent = nullptr);

	~CursorsArea();

	/**
	 * @brief cursorW is the cursor width
	 * @return
	 */
	int cursorW() const;

	/**
	 * @brief makeCursorsOpaque setThe opacity of cursors to 1
	 */
	Q_INVOKABLE void makeCursorsOpaque();

signals:
	/// @brief Edude QML warm
	void cursorWChanged(int cursorW);

public slots:
	void setEditor(icL::editor::EditorInternal * editor);

	/// Changes the width of cursor (on ratio qulifier change)
	void setCursorW(int cursorW);

	// QQuickItem interface
protected:
	QSGNode * updatePaintNode(QSGNode *, UpdatePaintNodeData *) override;

private:
	/// @brief permits to get cursors data from editor
	EditorInternal * editor = nullptr;

	/// @brief used to animate the alpha of the cursor
	Alpha alpha;

	/// @brief the width of cursor
	int m_cursorW;

	/// @brief the sg node, which will contains all cursors
	QSGOpacityNode * node = nullptr;
};

}  // namespace icL::editor

#endif  // icL_editor_CursorsArea
