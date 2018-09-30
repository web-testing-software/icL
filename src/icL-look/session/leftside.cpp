#include "leftside.h"

namespace icL::look::session {

LeftSide::LeftSide(QObject * parent)
	: Base(parent) {
	m_files    = new start::ListItem(this);
	m_projects = new Tree(this);
	m_switcher = new base::Link(this);
}

LeftSide::~LeftSide() {
	icL_dropField(m_files);
	icL_dropField(m_projects);
	icL_dropField(m_switcher);
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

}  // namespace icL::look::session
