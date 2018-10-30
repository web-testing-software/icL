#ifndef icL_editor_OpacityMask
#define EDITOROPACITYMASK_H

#include <QQuickPaintedItem>

namespace icL::editor {

class Drawing;

class OpacityMask : public QQuickPaintedItem
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Drawing * editor READ editor WRITE setEditor NOTIFY editorChanged)
	// clang-format on

public:
	explicit OpacityMask(QQuickItem * parent = nullptr);

	Drawing * editor() const;

	// QQuickPaintedItem interface
public:
	void paint(QPainter * painter) override;

signals:
	void editorChanged(Drawing * editor);

public slots:
	void setEditor(Drawing * editor);

private:
	Drawing * m_editor;
};

}  // namespace icL::editor

#endif  // icL_editor_OpacityMask
