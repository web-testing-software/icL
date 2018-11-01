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

CursorsArea::~CursorsArea() {
	node->removeAllChildNodes();
	qDebug() << "Cursor area crashed!";
}

int CursorsArea::cursorW() const {
	return m_cursorW;
}

void CursorsArea::setEditor(EditorInternal * editor) {
	if (this->editor == editor) {
		return;
	}

	this->editor = editor;
	update();
}

void CursorsArea::setCursorW(int cursorW) {
	if (m_cursorW == cursorW)
		return;

	m_cursorW = cursorW;
	emit cursorWChanged(m_cursorW);
}

QSGNode * CursorsArea::updatePaintNode(
  QSGNode *, QQuickItem::UpdatePaintNodeData *) {

	if (node == nullptr) {
		node = new QSGOpacityNode;
	}

	if (!alpha.update()) {
		if (alpha.currentAlpha >= 1.0) {
			alpha.setCurrentAlpha(0.0);
		}
		else {
			alpha.setCurrentAlpha(1.0);
		}
	}

	if (node->childCount() == 0) {
		auto * geometryNode = new QSGGeometryNode;
		auto * geometry =
		  new QSGGeometry{QSGGeometry::defaultAttributes_Point2D(), 2};

		geometry->setLineWidth(m_cursorW);
		geometry->setDrawingMode(QSGGeometry::DrawLines);
		geometryNode->setGeometry(geometry);

		node->appendChildNode(geometryNode);
	}

	if (editor == nullptr) {
		return node;
	}

	//	qDebug() << node << node->firstChild();

	auto * mainNode = dynamic_cast<QSGGeometryNode *>(node->childAtIndex(0));
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

	int yPos = line->lastY();

	if (line->visible()) {
		int xBegin =
		  -editor->xScroll * editor->m_proxy->charW() + m_cursorW / 2;
		int xPos = xBegin + cursor->getPosInLine() * editor->m_proxy->charW();

		vertices[0].set(xPos, yPos);
		vertices[1].set(xPos, yPos + editor->m_proxy->fullLineH());

		//		mainNode->setFlag(QSGNode::OwnsGeometry);
		node->markDirty(QSGNode::DirtyGeometry);
	}

	if (mainNode->material() == nullptr) {
		QSGFlatColorMaterial * material = new QSGFlatColorMaterial;
		material->setColor(cursor->fragment()->format().text.color());
		mainNode->setMaterial(material);
		//		mainNode->setFlag(QSGNode::OwnsMaterial);
	}

	node->setOpacity(alpha.currentAlpha);

	update();

	return node;
}

}  // namespace icL::editor
