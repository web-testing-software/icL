#include "topbar.h"

namespace icL::look::session {

TopBar::TopBar(QObject * parent)
	: Base(parent) {
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

}  // namespace icL::look::session
