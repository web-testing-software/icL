#ifndef icL_toolkit_tree_Folder
#define icL_toolkit_tree_Folder

#include "item.h"

#include <QList>



namespace icL::toolkit::tree {

/**
 * @brief The Folder class represents a tree item with cildren
 */
class Folder : public Item
{
public:
    /**
     * @brief Folder is the default contructor
     * @param parent is the default Item arg
     */
    Folder(Item * parent);

    /// @brief ~Folder deletes all children
    ~Folder();

    // Item interface
public:
    Item * child(int row) override;
    int    columnCount() override;
    int    childCount() override;

protected:
    /// @brief clear removes all child element
    void clear();

    /// @brief children is the array of pointer to child elements
    QList<Item *> children;

public:
    friend class Item;
};

}  // namespace icL::toolkit::tree

#endif  // icL_toolkit_tree_Folder
