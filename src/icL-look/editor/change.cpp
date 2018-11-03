#include "change.h"

namespace icL::look {

Change::Change(QObject * parent)
	: BaseLook(parent) {}

QColor Change::changed() const {
	return m_changed;
}

QColor Change::saved() const {
	return m_saved;
}

QColor Change::phantom() const {
	return m_phantom;
}

void Change::setChanged(const QColor & changed) {
	if (m_changed == changed)
		return;

	m_changed = changed;
	emit changedChanged(m_changed);
}

void Change::setSaved(const QColor & saved) {
	if (m_saved == saved)
		return;

	m_saved = saved;
	emit savedChanged(m_saved);
}

void Change::setPhantom(const QColor & phantom) {
	if (m_phantom == phantom)
		return;

	m_phantom = phantom;
	emit phantomChanged(m_phantom);
}

}  // namespace icL::look
