#include "centralside.h"

namespace icL::look::session {

CentralSide::CentralSide(QObject * parent)
	: Base(parent) {
	m_command = m_errorResult = m_okResult = QColor(Qt::transparent);

	m_error      = new Issue(this);
	m_header     = new base::Text(this);
	m_input      = new start::Input(this);
	m_underdigit = new base::LinkAdv(this);
	m_undertext  = new base::LinkAdv(this);
}

CentralSide::~CentralSide() {
	icL_dropField(m_error);
	icL_dropField(m_header);
	icL_dropField(m_input);
	icL_dropField(m_underdigit);
	icL_dropField(m_undertext);
	icL_dropField(m_warn);
}

base::Text * session::CentralSide::header() const {
	return m_header;
}

Issue * CentralSide::warn() const {
	return m_warn;
}

Issue * CentralSide::error() const {
	return m_error;
}

base::LinkAdv * CentralSide::undertext() const {
	return m_undertext;
}

base::LinkAdv * CentralSide::underdigit() const {
	return m_underdigit;
}

QColor CentralSide::command() const {
	return m_command;
}

QColor CentralSide::errorResult() const {
	return m_errorResult;
}

QColor CentralSide::okResult() const {
	return m_okResult;
}

start::Input * CentralSide::input() const {
	return m_input;
}

void CentralSide::setUp(const QJsonObject & obj) {
	m_header->setUp(obj.value("header").toObject());
	m_warn->setUp(obj.value("warn").toObject());
	m_error->setUp(obj.value("error").toObject());
	m_undertext->setUp(obj.value("undertext").toObject());
	m_underdigit->setUp(obj.value("underdigit").toObject());
	m_input->setUp(obj.value("input").toObject());

	m_command     = objToColor(obj.value("command").toObject());
	m_errorResult = objToColor(obj.value("error-result").toObject());
	m_okResult    = objToColor(obj.value("ok-result").toObject());

	emit commandChanged(m_command);
	emit errorResultChanged(m_errorResult);
	emit okResultChanged(m_okResult);
}

void CentralSide::setCommand(QColor command) {
	if (m_command == command)
		return;

	m_command = command;
	emit commandChanged(m_command);
}

void CentralSide::setErrorResult(QColor errorResult) {
	if (m_errorResult == errorResult)
		return;

	m_errorResult = errorResult;
	emit errorResultChanged(m_errorResult);
}

void CentralSide::setOkResult(QColor okResult) {
	if (m_okResult == okResult)
		return;

	m_okResult = okResult;
	emit okResultChanged(m_okResult);
}

}  // namespace icL::look::session
