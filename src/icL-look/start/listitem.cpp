#include "listitem.h"

namespace icL::look::start {

ListItem::ListItem(QObject * parent)
	: Link(parent) {}

ListItem::~ListItem() {
	if (m_border != nullptr) {
		delete m_border;
	}
}

base::Effect * ListItem::border() const {
	return m_border;
}

void ListItem::setBorder(base::Effect * border) {
	if (m_border == border)
		return;

	m_border = border;
	emit borderChanged(m_border);
}

}  // namespace icL::look::start
