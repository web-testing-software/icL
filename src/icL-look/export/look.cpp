#include "look.h"

namespace icL::look {

Look::Look(QObject * parent)
	: QObject(parent) {
	m_editor  = new editor::Editor(this);
	m_session = new session::SessionWindow(this);
	m_start   = new start::StartWindow(this);
}

Look::~Look() {
	icL_dropField(m_editor);
	icL_dropField(m_session);
	icL_dropField(m_start);
}

start::StartWindow * Look::start() const {
	return m_start;
}

session::SessionWindow * Look::session() const {
	return m_session;
}

editor::Editor * Look::editor() const {
	return m_editor;
}

void Look::setStart(start::StartWindow * start) {
	if (m_start == start)
		return;

	m_start = start;
	emit startChanged(m_start);
}

void Look::setSession(session::SessionWindow * session) {
	if (m_session == session)
		return;

	m_session = session;
	emit sessionChanged(m_session);
}

void Look::setEditor(editor::Editor * editor) {
	if (m_editor == editor)
		return;

	m_editor = editor;
	emit editorChanged(m_editor);
}

}  // namespace icL::look
