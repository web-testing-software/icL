#include "listitem.h"

#include "../base/effect.h"

#include <QJsonObject>

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

void ListItem::setUp(const QJsonObject & obj) {
	Link::setUp(obj);

	m_border->setUp(obj.value("border").toObject());
}

QJsonObject ListItem::getUp() {
	auto obj = Link::getUp();

	obj["border"] = m_border->getUp();

	return obj;
}

}  // namespace icL::look::start
