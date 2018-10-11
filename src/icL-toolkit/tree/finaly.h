#ifndef icL_toolkit_tree_Finaly
#define icL_toolkit_tree_Finaly

#include "item.h"



namespace icL::toolkit::tree {

class Finaly : public Item
{
public:
	Finaly(Item * parent);

	// Item interface
public:
	Item * child(int row) override;
	int    childCount() override;
};

}  // namespace icL::toolkit::tree

#endif  // icL_toolkit_tree_Finaly
