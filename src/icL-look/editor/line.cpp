#include "line.h"

#include "charformatbase.h"

#include <QJsonObject>

namespace icL::look {

Line::Line(QObject * parent)
	: BaseLook(parent) {
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
	m_lineNumber->setUp(obj.value("line-number").toObject());
	m_lineBg = objToColor(obj.value("line-bg").toObject());

	emit lineBgChanged(m_lineBg);
}

QJsonObject Line::getUp() {
	return {{"line-number", m_lineNumber->getUp()},
			{"line-bg", colorToObj(m_lineBg)}};
}

void Line::setLineBg(QColor lineBg) {
	if (m_lineBg == lineBg)
		return;

	m_lineBg = lineBg;
	emit lineBgChanged(m_lineBg);
}

}