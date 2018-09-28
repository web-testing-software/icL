#include "side.h"

namespace icL::look::start {

Side::Side(QObject * parent)
	: ListItem(parent) {}

Side::~Side() {
	if (m_header != nullptr) {
		delete m_header;
	}
}

base::Text * Side::header() const {
	return m_header;
}

QColor Side::background() const {
	return m_background;
}

void Side::setHeader(base::Text * header) {
	if (m_header == header)
		return;

	m_header = header;
	emit headerChanged(m_header);
}

void Side::setBackground(QColor background) {
	if (m_background == background)
		return;

	m_background = background;
	emit backgroundChanged(m_background);
}

}  // namespace icL::look::start
