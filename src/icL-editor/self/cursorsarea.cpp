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
	if (node != nullptr) {
		node->removeAllChildNodes();
	}
}

int CursorsArea::cursorW() const {
	return m_cursorW;
}

void CursorsArea::makeCursorsOpaque() {
	alpha.forceSetCurrentAlpha(1.0);
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

	int yPos   = line->lastY();
	int halfW  = m_cursorW / 2;
	int xBegin = -editor->xScroll * editor->m_proxy->charW() + halfW;
	int xPos   = xBegin + cursor->getPosInLine() * editor->m_proxy->charW();
	int hLen   = m_cursorW * 2;

	if (xPos < 0) {
		xPos = halfW - editor->proxy()->charH() / 2;
	}
	else if (xPos >= width()) {
		xPos = width() - halfW;
	}
	else if (line->visible()) {
		hLen = editor->m_proxy->fullLineH();
	}

	if (!line->visible()) {
		if (line->lineNumber() < editor->m_firstVisible->lineNumber()) {
			yPos = 0;
		}
		else {
			yPos = height() - hLen;
		}
	}

	vertices[0].set(xPos, yPos);
	vertices[1].set(xPos, yPos + hLen);

	mainNode->setFlag(QSGNode::OwnsGeometry);
	mainNode->markDirty(QSGNode::DirtyGeometry);

	QSGFlatColorMaterial * material;
	if (mainNode->material() == nullptr) {
		material = new QSGFlatColorMaterial;
		mainNode->setFlag(QSGNode::OwnsMaterial);
	}
	else {
		material = dynamic_cast<QSGFlatColorMaterial *>(mainNode->material());
	}

	material->setColor(cursor->fragment()->format().text.color());
	mainNode->setMaterial(material);

	node->setOpacity(alpha.currentAlpha);

	if (editor->hasActiveFocus()) {
		update();
	}

	return node;
}

}  // namespace icL::editor
