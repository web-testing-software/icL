#include "tree.h"

#include "../base/link.h"

#include <QJsonObject>

namespace icL::look {

Tree::Tree(QObject * parent)
	: BaseLook(parent) {
	m_parent = new Link(this);
	m_child  = new Link(this);
}

Tree::~Tree() {
	icL_dropField(m_parent);
	icL_dropField(m_child);
}

Link * Tree::parent() const {
	return m_parent;
}

Link * Tree::child() const {
	return m_child;
}

void Tree::setUp(const QJsonObject & obj) {
	m_parent->setUp(obj.value("parent").toObject());
	m_child->setUp(obj.value("child").toObject());
}

QJsonObject Tree::getUp() {
	return {{"parent", m_parent->getUp()}, {"child", m_child->getUp()}};
}

}
