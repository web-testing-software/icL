#ifndef RESOURCES_H
#define RESOURCES_H

#include "../tree/folder.h"



namespace icL::toolkit::session {

class Resources : public tree::Folder
{
public:
	Resources(Item * parent);

	// Item interface
public:
	QVariant data(int column) override;
	QString  getIcon() override;
};

}  // namespace icL::toolkit::session

#endif  // RESOURCES_H
