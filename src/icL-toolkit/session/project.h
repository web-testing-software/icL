#ifndef icL_toolkit_session_Project
#define icL_toolkit_session_Project

#include "../tree/item.h"



namespace icL::toolkit::session {

class Project : tree::Item
{
public:
	Project(Item * parent);


	// Item interface
public:
	tree::Item * child(int row) override;
	int          childCount() override;
	int          columnCount() override;
	QVariant     data(int column) override;
	QString      getIcon() override;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Project
