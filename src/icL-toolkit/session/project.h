#ifndef icL_toolkit_session_Project
#define icL_toolkit_session_Project

#include "../tree/item.h"


class Script;
class Libs;
class Resources;

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

private:
	Script *    script    = nullptr;
	Libs *      libs      = nullptr;
	Resources * resources = nullptr;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Project
