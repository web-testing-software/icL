#ifndef icL_toolkit_tree_Item
#define icL_toolkit_tree_Item



class QVariant;
class QString;
class QStringList;
template <typename T>
class QList;

namespace icL::toolkit::utils {
class RemoteCall;
using Actions = QList<RemoteCall *>;
}  // namespace icL::toolkit::utils

/**
 * @brief The icL.toolkit.tree namespace contains base classes of a tree model
 */
namespace icL::toolkit::tree {

/**
 * @brief The Item class describes any tree item commom interface
 */
class Item
{
public:
    /**
     * @brief Item is the deafult constructor
     * @param parent is the parent element in tree
     */
    Item(Item * parent);

    /// @brief ~Item is the deafult virtual constructor
    virtual ~Item();

    /**
     * @brief child returns the row-th child
     * @param row is the order number
     * @return pointer to a child element
     */
    virtual Item * child(int row) = 0;

    /**
     * @brief childCount returns the number of child elements
     * @return the number of child elements
     */
    virtual int childCount() = 0;

    /**
     * @brief columnCount returns the number of columns in row
     * @return the number of cells in row
     */
    virtual int columnCount() = 0;

    /**
     * @brief data returns cell data
     * @param column is the cell order number
     * @return the data of cell
     */
    virtual QVariant data(int column) = 0;

    /**
     * @brief selfIndex returns the self index in parent children
     * @return the self index in parent children
     */
    virtual int selfIndex();

    /**
     * @brief parent returns the pointer to the parent item
     * @return the pointer to the parent or null for root
     */
    virtual Item * parent();

    /**
     * @brief getIcon returns the name of icon in theme
     * @return the name of icon int theme
     */
    virtual QString getIcon() = 0;

    /**
     * @brief getActionsList get aviable actions list
     * @return the list of aviable actions as JSON string
     */
    virtual const utils::Actions & getActionsList() = 0;

    /**
     * @brief runAction run a action
     * @param arg is JSON string with action name and args
     * @return true if the needed action was executed successful, otherwise
     * false
     */
    virtual bool runAction(utils::RemoteCall * call) = 0;

private:
    /**
     * @brief clear clears the memory of action list
     */
    void clear();

protected:
    /// @brief m_parent is the pointer to the parent item
    Item * m_parent = nullptr;
};

}  // namespace icL::toolkit::tree

#endif  // icL_toolkit_tree_Item
