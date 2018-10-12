#ifndef icL_toolkit_tree_Item
#define icL_toolkit_tree_Item



class QVariant;
class QString;

namespace icL::toolkit::tree {

class Item
{
public:
	Item(Item * parent);
	virtual ~Item() = default;

	virtual Item *   child(int row)   = 0;
	virtual int      childCount()     = 0;
	virtual int      columnCount()    = 0;
	virtual QVariant data(int column) = 0;
	virtual int      selfIndex();
	virtual Item *   parent();
	virtual QString  getIcon() = 0;

protected:
	Item * m_parent = nullptr;
};

}  // namespace icL::toolkit::tree

#endif  // icL_toolkit_tree_Item
