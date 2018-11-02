#ifndef icL_toolkit_tree_Finaly
#define icL_toolkit_tree_Finaly

#include "item.h"



namespace icL::toolkit::tree {

/**
 * @brief The Finaly class represent an item without children
 */
class Finaly : public Item
{
public:
	/**
	 * @brief Finaly is the default constructor
	 * @param parent is the default Item arg
	 */
	Finaly(Item * parent);

	// Item interface
public:
	Item * child(int row) override;
	int    childCount() override;

protected:
	bool checkIfFileExist(const QString & path, QString & fname);
};

}  // namespace icL::toolkit::tree

#endif  // icL_toolkit_tree_Finaly
