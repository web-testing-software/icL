#include "line.h"

namespace icL::look::editor {

Line::Line(QObject * parent)
	: Base(parent) {
	m_lineBg     = QColor(Qt::transparent);
	m_lineNumber = new CharFormatBase(this);
}

Line::~Line() {
	icL_dropField(m_lineNumber);
}

QColor Line::lineBg() const {
	return m_lineBg;
}

CharFormatBase * Line::lineNumber() const {
	return m_lineNumber;
}

void Line::setUp(const QJsonObject & obj) {
	m_lineNumber->setUp(obj.value("lineNumber").toObject());
	m_lineBg = objToColor(obj.value("lineBg").toObject());

	emit lineBgChanged(m_lineBg);
}

void Line::setLineBg(QColor lineBg) {
	if (m_lineBg == lineBg)
		return;

	m_lineBg = lineBg;
	emit lineBgChanged(m_lineBg);
}

}  // namespace icL::look::editor
