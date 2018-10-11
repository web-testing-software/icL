#ifndef icL_toolkit_tree_Folder
#define icL_toolkit_tree_Folder

#include "item.h"

#include <QList>



namespace icL::toolkit::tree {

class Folder : public Item
{
public:
	Folder(Item * parent);

	// Item interface
public:
	Item * child(int row) override;
	int    columnCount() override;
	int    childCount() override;

protected:
	QList<Item *> children;

public:
	friend class Item;
};

}  // namespace icL::toolkit::tree

#endif  // icL_toolkit_tree_Folder
