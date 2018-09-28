#include "tree.h"

namespace icL::look::session {

Tree::Tree(QObject * parent)
	: QObject(parent) {}

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

void Tree::setParent(base::Link * parent) {
	if (m_parent == parent) {
		return;
	}

	m_parent = parent;
	emit parentChanged(m_parent);
}

void Tree::setChild(base::Link * child) {
	if (m_child == child) {
		return;
	}

	m_child = child;
	emit childChanged(m_child);
}

}  // namespace icL::look::session
