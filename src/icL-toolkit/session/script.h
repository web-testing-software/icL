#ifndef SCRIPT_H
#define SCRIPT_H

#include "../tree/finaly.h"

#include <QString>



namespace icL::toolkit::session {

/**
 * @brief The Script class describes a icL script
 */
class Script : public tree::Finaly
{
public:
	/**
	 * @brief Script is the default constructor
	 * @param parent is the default Item arg
	 */
	Script(Item * parent);

	/**
	 * @brief setPath sets up the script
	 * @param path is the path to script file
	 * @return true if so files exists, otherwise false
	 */
	bool setPath(const QString & path);

	// Item interface
public:
	int      columnCount() override;
	QVariant data(int column) override;
	int      selfIndex() override;
	QString  getIcon() override;

private:
	/// @brief name is the display name
	QString name;
};

}  // namespace icL::toolkit::session

#endif  // SCRIPT_H
