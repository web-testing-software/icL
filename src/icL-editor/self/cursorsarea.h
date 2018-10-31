#ifndef CURSORSAREA_H
#define CURSORSAREA_H

#include "../private/alpha.h"

#include <QQuickItem>

namespace icL::editor {

class EditorInternal;

class CursorsArea : public QQuickItem
{
	Q_OBJECT
public:
	explicit CursorsArea(QQuickItem * parent = nullptr);

signals:

public slots:
	void setEditor(icL::editor::EditorInternal * editor);

	// QQuickItem interface
protected:
	QSGNode * updatePaintNode(
	  QSGNode * oldNode, UpdatePaintNodeData *) override;

private:
	EditorInternal * editor = nullptr;

	Alpha alpha;
};

}  // namespace icL::editor

#endif  // CURSORSAREA_H
