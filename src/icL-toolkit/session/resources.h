#ifndef RESOURCES_H
#define RESOURCES_H

#include "../tree/folder.h"



namespace icL::toolkit::session {

/**
 * @brief The Resources class describes a resource folder
 */
class Resources : public tree::Folder
{
public:
	/**
	 * @brief Resources is the default constructor
	 * @param parent is the default Item arg
	 */
	Resources(Item * parent);

	/**
	 * @brief setResourceList set up the resource folder
	 * @param files is the list of initial resources
	 * @return true if resources exist, otherwise false
	 */
	bool setResourceList(const QString & path, const QVariantList & files);

	// Item interface
public:
	QVariant data(int column) override;
	QString  getIcon() override;
};

}  // namespace icL::toolkit::session

#endif  // RESOURCES_H
