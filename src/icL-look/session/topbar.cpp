#include "topbar.h"

namespace icL::look::session {

TopBar::TopBar(QObject * parent)
	: QObject(parent) {
	m_cursor = QColor(Qt::transparent);
	m_button = new base::EffectAdv(this);
	m_input  = new base::Text(this);
	m_tab    = new base::LinkAdv(this);
	m_tool   = new base::EffectAdv(this);
	m_url    = new base::LinkAdv(this);
}

TopBar::~TopBar() {
	icL_dropField(m_button);
	icL_dropField(m_input);
	icL_dropField(m_tab);
	icL_dropField(m_tool);
	icL_dropField(m_url);
}

base::LinkAdv * TopBar::tab() const {
	return m_tab;
}

base::LinkAdv * TopBar::url() const {
	return m_url;
}

base::EffectAdv * TopBar::button() const {
	return m_button;
}

base::EffectAdv * TopBar::tool() const {
	return m_tool;
}

base::Text * TopBar::input() const {
	return m_input;
}

QColor TopBar::cursor() const {
	return m_cursor;
}

void icL::look::session::TopBar::setTab(base::LinkAdv * tab) {
	if (m_tab == tab)
		return;

	m_tab = tab;
	emit tabChanged(m_tab);
}

void TopBar::setUrl(base::LinkAdv * url) {
	if (m_url == url)
		return;

	m_url = url;
	emit urlChanged(m_url);
}

void TopBar::setButton(base::EffectAdv * button) {
	if (m_button == button)
		return;

	m_button = button;
	emit buttonChanged(m_button);
}

void TopBar::setTool(base::EffectAdv * tool) {
	if (m_tool == tool)
		return;

	m_tool = tool;
	emit toolChanged(m_tool);
}

void TopBar::setInput(base::Text * input) {
	if (m_input == input)
		return;

	m_input = input;
	emit inputChanged(m_input);
}

void TopBar::setCursor(QColor cursor) {
	if (m_cursor == cursor)
		return;

	m_cursor = cursor;
	emit cursorChanged(m_cursor);
}

}  // namespace icL::look::session
