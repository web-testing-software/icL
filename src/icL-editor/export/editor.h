#ifndef icL_editor_Editor
#define icL_editor_Editor

#include <QQuickPaintedItem>



namespace icL::editor {

class Editor : public QQuickPaintedItem
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::look::EditorStyle*   style READ style        WRITE setStyle        NOTIFY styleChanged)
	Q_PROPERTY(icL::editor::Selection*    main READ main         WRITE setMain         NOTIFY mainChanged)
	Q_PROPERTY(icL::editor::Line*        first READ first        WRITE setFirst        NOTIFY firstChanged)
	Q_PROPERTY(icL::editor::Line*      current READ current      WRITE setCurrent      NOTIFY currentChanged)
	Q_PROPERTY(icL::editor::Line* firstVisible READ firstVisible WRITE setFirstVisible NOTIFY firstVisibleChanged)
	Q_PROPERTY(icL::editor::Line*  lastVisible READ lastVisible  WRITE setLastVisible  NOTIFY lastVisibleChanged)
	// clang-format on

public:
	Editor(QQuickItem * parent);
};

}  // namespace icL::editor

#endif  // icL_editor_Editor
