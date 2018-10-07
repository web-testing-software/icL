#include "panels.h"

#include "../panels/browser.h"
#include "../panels/code.h"
#include "../panels/debug.h"

namespace icL::toolkit::panels {

Panels::Panels(QObject * parent)
	: QObject(parent) {
	m_browser = new Browser(this);
	m_code    = new Code(this);
	m_debug   = new Debug(this);
}

Panels::~Panels() {
	m_browser->deleteLater();
	m_code->deleteLater();
	m_debug->deleteLater();
}

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
