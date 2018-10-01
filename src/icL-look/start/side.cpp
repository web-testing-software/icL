#include "side.h"

#include "../base/linkadv.h"
#include "../base/text.h"
#include "input.h"

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

Input * Side::input() const {
	return m_input;
}

base::LinkAdv * Side::button() const {
	return m_button;
}

void Side::setUp(const QJsonObject & obj) {
	ListItem::setUp(obj);

	m_header->setUp(obj.value("header").toObject());
	m_input->setUp(obj.value("input").toObject());
	m_button->setUp(obj.value("button").toObject());

	m_background = objToColor(obj.value("background").toObject());

	emit backgroundChanged(m_background);
}

QJsonObject Side::getUp() {
	auto obj = ListItem::getUp();

	obj["header"]     = m_header->getUp();
	obj["background"] = colorToObj(m_background);
	obj["input"]      = m_input->getUp();
	obj["button"]     = m_button->getUp();

	return obj;
}

}  // namespace icL::look::start
