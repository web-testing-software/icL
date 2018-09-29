#include "centralside.h"

namespace icL::look::session {

CentralSide::CentralSide(QObject * parent)
	: QObject(parent) {}

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

void CentralSide::setHeader(base::Text * header) {
	if (m_header == header)
		return;

	m_header = header;
	emit headerChanged(m_header);
}

void CentralSide::setWarn(Issue * warn) {
	if (m_warn == warn)
		return;

	m_warn = warn;
	emit warnChanged(m_warn);
}

void CentralSide::setError(Issue * error) {
	if (m_error == error)
		return;

	m_error = error;
	emit errorChanged(m_error);
}

void CentralSide::setUndertext(base::LinkAdv * undertext) {
	if (m_undertext == undertext)
		return;

	m_undertext = undertext;
	emit undertextChanged(m_undertext);
}

void CentralSide::setUnderdigit(base::LinkAdv * underdigit) {
	if (m_underdigit == underdigit)
		return;

	m_underdigit = underdigit;
	emit underdigitChanged(m_underdigit);
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

void CentralSide::setInput(start::Input * input) {
	if (m_input == input)
		return;

	m_input = input;
	emit inputChanged(m_input);
}

}  // namespace icL::look::session
