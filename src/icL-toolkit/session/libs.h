#ifndef icL_toolkit_session_Libs
#define icL_toolkit_session_Libs

#include "../tree/folder.h"



namespace icL::toolkit::session {

/**
 * @brief The Libs class describes a libs folder
 */
class Libs : tree::Folder
{
public:
	/**
	 * @brief Libs is the default constructor
	 * @param parent is the default Item arg
	 */
	Libs(Item * parent);

	/**
	 * @brief setLibsList setup the list of libs
	 * @param libs is the new libs list
	 * @return true if all libs exist, otherwise false
	 */
	bool setLibsList(const QStringList & libs);

	// Item interface
public:
	QVariant data(int column) override;
	QString  getIcon() override;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Libs
