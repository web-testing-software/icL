#include "input.h"

namespace icL::look::start {

Input::Input(QObject * parent)
	: Link(parent) {
	m_cursor = QColor(Qt::transparent);

	m_inactive  = new base::Text(this);
	m_selection = new base::Text(this);
}

Input::~Input() {
	icL_dropField(m_inactive);
	icL_dropField(m_selection);
}

base::Text * Input::inactive() const {
	return m_inactive;
}

base::Text * Input::selection() const {
	return m_selection;
}

QColor Input::cursor() const {
	return m_cursor;
}

void Input::setUp(const QJsonObject & obj) {
	Link::setUp(obj);

	m_inactive->setUp(obj.value("inactive").toObject());
	m_selection->setUp(obj.value("selection").toObject());

	m_cursor = objToColor(obj.value("cursor").toObject());

	emit cursorChanged(m_cursor);
}

QJsonObject Input::getUp() {
	auto obj = Link::getUp();

	obj["inactive"]  = m_inactive->getUp();
	obj["selection"] = m_selection->getUp();
	obj["cursor"]    = colorToObj(m_cursor);

	return obj;
}

void Input::setCursor(QColor cursor) {
	if (m_cursor == cursor)
		return;

	m_cursor = cursor;
	emit cursorChanged(m_cursor);
}

}  // namespace icL::look::start
