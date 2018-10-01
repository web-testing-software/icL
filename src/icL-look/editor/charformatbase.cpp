#include "charformatbase.h"

#include <QJsonObject>

namespace icL::look::editor {

CharFormatBase::CharFormatBase(QObject * parent)
	: Text(parent) {
	m_bold = m_italic = false;
}

bool CharFormatBase::bold() const {
	return m_bold;
}

bool CharFormatBase::italic() const {
	return m_italic;
}

void CharFormatBase::setUp(const QJsonObject & obj) {
	Text::setUp(obj);

	m_bold   = obj.value("bold").toBool();
	m_italic = obj.value("italic").toBool();
}

QJsonObject CharFormatBase::getUp() {
	auto obj = Text::getUp();

	obj["bold"]   = m_bold;
	obj["italic"] = m_italic;

	return obj;
}

void CharFormatBase::setBold(bool bold) {
	if (m_bold == bold)
		return;

	m_bold = bold;
	emit boldChanged(m_bold);
}

void CharFormatBase::setItalic(bool italic) {
	if (m_italic == italic)
		return;

	m_italic = italic;
	emit italicChanged(m_italic);
}

}  // namespace icL::look::editor
