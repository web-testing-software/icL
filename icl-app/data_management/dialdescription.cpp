#include "dialdescription.h"

DialDescription::DialDescription(QObject* parent)
	: QObject(parent) {}

/**
 * @brief DialDescription::count - count getter
 * @return m_count
 */
int DialDescription::count() const {
	return m_count;
}

/**
 * @brief DialDescription::title - title getter
 * @return m_title
 */
QString DialDescription::title() const {
	return m_title;
}

/**
 * @brief DialDescription::url - url getter
 * @return m_url
 */
QString DialDescription::url() const {
	return m_url;
}

/**
 * @brief DialDescription::setCount - count setter
 * @param count - value
 */
void DialDescription::setCount(int count) {
	if (m_count == count) {
		return;
	}

	m_count = count;
	emit countChanged(m_count);
}

/**
 * @brief DialDescription::setTitle - title setter
 * @param title - value
 */
void DialDescription::setTitle(const QString& title) {
	if (m_title == title) {
		return;
	}

	m_title = title;
	emit titleChanged(m_title);
}

/**
 * @brief DialDescription::setUrl - url setter
 * @param - url value
 */
void DialDescription::setUrl(const QString& url) {
	if (m_url == url) {
		return;
	}

	m_url = url;
	emit urlChanged(m_url);
}
