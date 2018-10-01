#include "side.h"

#include "../base/text.h"

#include <QJsonObject>

namespace icL::look::start {

Side::Side(QObject * parent)
	: ListItem(parent) {
	m_background = QColor(Qt::transparent);
	m_header     = new base::Text(this);
}

Side::~Side() {
	icL_dropField(m_header);
}

base::Text * Side::header() const {
	return m_header;
}

QColor Side::background() const {
	return m_background;
}

void Side::setUp(const QJsonObject & obj) {
	ListItem::setUp(obj);

	m_header->setUp(obj.value("header").toObject());

	m_background = objToColor(obj.value("background").toObject());

	emit backgroundChanged(m_background);
}

QJsonObject Side::getUp() {
	auto obj = ListItem::getUp();

	obj["header"]     = m_header->getUp();
	obj["background"] = colorToObj(m_background);

	return obj;
}

void Side::setBackground(QColor background) {
	if (m_background == background)
		return;

	m_background = background;
	emit backgroundChanged(m_background);
}

}  // namespace icL::look::start
