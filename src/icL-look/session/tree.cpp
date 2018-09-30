#include "tree.h"

namespace icL::look::session {

Tree::Tree(QObject * parent)
	: Base(parent) {
	m_parent = new base::Link(this);
	m_child  = new base::Link(this);
}

Tree::~Tree() {
	icL_dropField(m_parent);
	icL_dropField(m_child);
}

base::Link * Tree::parent() const {
	return m_parent;
}

base::Link * Tree::child() const {
	return m_child;
}

void Tree::setUp(const QJsonObject & obj) {
	m_parent->setUp(obj.value("parent").toObject());
	m_child->setUp(obj.value("child").toObject());
}

}  // namespace icL::look::session
