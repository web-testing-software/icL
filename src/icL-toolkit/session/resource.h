#ifndef icL_toolkit_session_Resource
#define icL_toolkit_session_Resource

#include "../tree/finaly.h"

#include <QString>



namespace icL::toolkit::session {

/**
 * @brief The Resource class describe a resource in icL
 */
class Resource : public tree::Finaly
{
public:
	/**
	 * @brief Resource is the default constructor
	 * @param parent is the default Item arg
	 */
	Resource(Item * parent);

	/**
	 * @brief setPath sets up the resource item
	 * @param path is the path to the file
	 * @return true if file exists, otherwise false
	 */
	bool setPath(const QString & path);

	// Item interface
public:
	int      columnCount() override;
	QVariant data(int column) override;
	int      selfIndex() override;
	QString  getIcon() override;

	const utils::Actions & getActionsList() override;

	bool runAction(utils::RemoteCall * call) override;

private:
	/// @brief resurceName is the display name
	QString resourceName;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Resource
