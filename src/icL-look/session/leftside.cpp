#include "leftside.h"

namespace icL::look::session {

LeftSide::LeftSide(QObject * parent)
	: QObject(parent) {}

LeftSide::~LeftSide() {
	if (m_files != nullptr) {
		delete m_files;
	}

	if (m_projects != nullptr) {
		delete m_projects;
	}

	if (m_switcher != nullptr) {
		delete m_switcher;
	}
}

base::Link * LeftSide::switcher() const {
	return m_switcher;
}

Tree * LeftSide::projects() const {
	return m_projects;
}

start::ListItem * LeftSide::files() const {
	return m_files;
}

void LeftSide::setSwitcher(base::Link * switcher) {
	if (m_switcher == switcher)
		return;

	m_switcher = switcher;
	emit switcherChanged(m_switcher);
}

void LeftSide::setProjects(Tree * projects) {
	if (m_projects == projects)
		return;

	m_projects = projects;
	emit projectsChanged(m_projects);
}

void LeftSide::setFiles(start::ListItem * files) {
	if (m_files == files)
		return;

	m_files = files;
	emit filesChanged(m_files);
}

}  // namespace icL::look::session
