#ifndef icL_editor_OpacityMask
#define EDITOROPACITYMASK_H

#include <QQuickPaintedItem>

namespace icL::editor {

class EditorInternal;

class OpacityMask : public QQuickPaintedItem
{
	Q_OBJECT

public:
	explicit OpacityMask(QQuickItem * parent = nullptr);

	// QQuickPaintedItem interface
public:
	void paint(QPainter * painter) override;

signals:

public slots:
	void setEditor(EditorInternal * editor);

private:
	EditorInternal * m_editor;
};

}  // namespace icL::editor

#endif  // icL_editor_OpacityMask
