#ifndef icL_toolkit_session_Project
#define icL_toolkit_session_Project

#include "../tree/item.h"


class Script;
class Libs;
class Resources;

namespace icL::toolkit::session {

/**
 * @brief The Project class describes a icL project
 */
class Project : public tree::Item
{
public:
	/**
	 * @brief Project is the default constructor
	 * @param parent is the default Item arg
	 */
	Project(Item * parent);

	/**
	 * @brief loadProject loads a project from folder path
	 * @param path is the path to the project folder
	 * @return true if loadded successfull, otherwise false
	 */
	bool loadProject(const QString & path);

	// Item interface
public:
	tree::Item * child(int row) override;
	int          childCount() override;
	int          columnCount() override;
	QVariant     data(int column) override;
	QString      getIcon() override;

private:
	/// @brief script is the executable file of project
	Script * script = nullptr;

	/// @brief libs is the folder with libs files
	Libs * libs = nullptr;

	/// @brief resources is the resource folder
	Resources * resources = nullptr;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Project
