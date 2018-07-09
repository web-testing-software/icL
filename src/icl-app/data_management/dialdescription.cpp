#include "dialdescription.h"

namespace icL::app {

DialDescription::DialDescription(QObject * parent)
	: QObject(parent) {}

int DialDescription::count() const {
	return m_count;
}

QString DialDescription::title() const {
	return m_title;
}

QString DialDescription::url() const {
	return m_url;
}

void DialDescription::setCount(int count) {
	if (m_count == count) {
		return;
	}

	m_count = count;
	emit countChanged(m_count);
}

void DialDescription::setTitle(const QString & title) {
	if (m_title == title) {
		return;
	}

	m_title = title;
	emit titleChanged(m_title);
}

void DialDescription::setUrl(const QString & url) {
	if (m_url == url) {
		return;
	}

	m_url = url;
	emit urlChanged(m_url);
}

}  // namespace icL::app
