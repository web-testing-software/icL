#include "cursorsarea.h"

#include "../fragment/fragment.h"
#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "../private/styleproxy.h"
#include "editorinternal.h"

#include <icL-look/export/chars.h>

#include <QSGFlatColorMaterial>
#include <QSGGeometryNode>

namespace icL::editor {

CursorsArea::CursorsArea(QQuickItem * parent)
	: QQuickItem(parent) {
	setFlag(ItemHasContents, true);

	alpha.setInterval(1000);
	alpha.forceSetCurrentAlpha(0.0);
	alpha.setCurrentAlpha(1.0);
}

void CursorsArea::setEditor(EditorInternal * editor) {
	if (this->editor == editor) {
		return;
	}

	this->editor = editor;
	update();
}

QSGNode * CursorsArea::updatePaintNode(
  QSGNode * oldNode, QQuickItem::UpdatePaintNodeData *) {
	QSGOpacityNode * node = nullptr;

	if (!alpha.update()) {
		if (alpha.currentAlpha >= 1.0) {
			alpha.setCurrentAlpha(0.0);
		}
		else {
			alpha.setCurrentAlpha(1.0);
		}
	}

	if (!oldNode) {
		node = new QSGOpacityNode();
	}
	else {
		node = dynamic_cast<QSGOpacityNode *>(oldNode);
	}

	if (editor == nullptr) {
		return node;
	}

	if (node->childCount() == 0) {
		auto * geometryNode = new QSGGeometryNode;
		auto * geometry =
		  new QSGGeometry{QSGGeometry::defaultAttributes_Point2D(), 2};

		geometry->setLineWidth(editor->m_proxy->lineS());
		geometry->setDrawingMode(QSGGeometry::DrawLines);
		geometryNode->setGeometry(geometry);

		node->appendChildNode(geometryNode);
	}

	int xBegin = -editor->xScroll * editor->m_proxy->charW();

	auto * mainNode = dynamic_cast<QSGGeometryNode *>(node->childAtIndex(1));
	auto * mainGeometry = mainNode->geometry();

	QSGGeometry::Point2D * vertices = mainGeometry->vertexDataAsPoint2D();

	Cursor * cursor;

	if (editor->m_main->rtl()) {
		cursor = editor->m_main->begin();
	}
	else {
		cursor = editor->m_main->end();
	}

	auto * line = cursor->fragment()->line();

	if (line->visible()) {
		int yPos = line->lastY();
		int xPos = xBegin + cursor->getPosInLine() * editor->m_proxy->charW();

		vertices[0].set(xPos, yPos);
		vertices[1].set(xPos, editor->m_proxy->fullLineH());
	}

	QSGFlatColorMaterial * material = new QSGFlatColorMaterial;
	material->setColor(cursor->fragment()->format().text.color());
	mainNode->setMaterial(material);
	mainNode->setFlag(QSGNode::OwnsMaterial);
	mainNode->setFlag(QSGNode::OwnsGeometry);

	node->markDirty(QSGNode::DirtyGeometry);
	node->setOpacity(alpha.currentAlpha);

	return node;
}

}  // namespace icL::editor
