#include "listitem.h"

namespace icL::look::start {

ListItem::ListItem(QObject * parent)
	: Link(parent) {
	m_border = new base::Effect(this);
}

ListItem::~ListItem() {
	icL_dropField(m_border);
}

base::Effect * ListItem::border() const {
	return m_border;
}

}  // namespace icL::look::start
