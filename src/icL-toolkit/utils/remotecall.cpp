#include "remotecall.h"

#include <utility>

namespace icL::toolkit::utils {

RemoteArg::RemoteArg(const QString & name) {
	m_name = name;
}

QString RemoteArg::name() const {
	return m_name;
}

QVariant RemoteArg::value() const {
	return m_value;
}

void RemoteArg::setValue(const QVariant & value) {
	if (m_value == value)
		return;

	m_value = value;
	emit valueChanged(m_value);
}

RemoteCall::RemoteCall(int id, QString name, QList<RemoteArg *> args) {
	m_id   = id;
	m_name = std::move(name);
	m_args = std::move(args);
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
