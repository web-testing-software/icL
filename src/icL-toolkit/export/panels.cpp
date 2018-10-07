#include "panels.h"

namespace icL::toolkit::panels {

Panels::Panels(QObject * parent)
	: QObject(parent) {}

Browser * Panels::browser() const {
	return m_browser;
}

Code * Panels::code() const {
	return m_code;
}

Debug * Panels::debug() const {
	return m_debug;
}

bool Panels::projectsOrFiles() const {
	return m_projectsOrFiles;
}

void Panels::setProjectsOrFiles(bool projectsOrFiles) {
	if (m_projectsOrFiles == projectsOrFiles)
		return;

	m_projectsOrFiles = projectsOrFiles;
	emit projectsOrFilesChanged(m_projectsOrFiles);
}

}  // namespace icL::toolkit::panels
