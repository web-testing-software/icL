#include "leftside.h"

#include "../start/listitem.h"
#include "tree.h"

#include <QJsonObject>

namespace icL::look {

LeftSide::LeftSide(QObject * parent)
    : BaseLook(parent) {
	m_files    = new ListItem(this);
	m_projects = new Tree(this);
	m_switcher = new Link(this);
}

LeftSide::~LeftSide() {
	delete m_files;
	delete m_projects;
	delete m_switcher;
}

Link * LeftSide::switcher() const {
	return m_switcher;
}

Tree * LeftSide::projects() const {
	return m_projects;
}

ListItem * LeftSide::files() const {
	return m_files;
}

void LeftSide::setUp(const QJsonObject & obj) {
	m_switcher->setUp(obj.value("switcher").toObject());
	m_projects->setUp(obj.value("projects").toObject());
	m_files->setUp(obj.value("files").toObject());
}

QJsonObject LeftSide::getUp() {
	return {{"switcher", m_switcher->getUp()},
	        {"projects", m_projects->getUp()},
	        {"files", m_files->getUp()}};
}

}  // namespace icL::look
