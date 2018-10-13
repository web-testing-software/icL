#include "remotecall.h"

namespace icL::toolkit::utils {

QString RemoteArg::name() const {
	return m_name;
}

QVariant RemoteArg::value() const {
	return m_value;
}

void RemoteArg::setValue(QVariant value) {
	if (m_value == value)
		return;

	m_value = value;
	emit valueChanged(m_value);
}

RemoteCall::RemoteCall(int id, QString name, QList<RemoteArg *> args) {
	m_id   = id;
	m_name = name;
	m_args = args;
}

int RemoteCall::id() const {
	return m_id;
}

QString RemoteCall::name() const {
	return m_name;
}

QList<RemoteArg *> RemoteCall::args() const {
	return m_args;
}

}  // namespace icL::toolkit::utils
