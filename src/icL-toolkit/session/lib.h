#ifndef LIB_H
#define LIB_H

#include "../tree/finaly.h"

#include <QString>



namespace icL::toolkit::session {

/**
 * @brief The Lib class represents a lib in a project
 */
class Lib : public tree::Finaly
{
public:
	/**
	 * @brief Lib is the default constructor
	 * @param parent is the default Item arg
	 */
	Lib(Item * parent);

	/**
	 * @brief setPath set the path to the lib
	 * @param path is the path to the lib
	 * @return bool is so file exists, otherwise false
	 */
	bool setPath(const QString & path);

	// Item interface
public:
	int      columnCount() override;
	QVariant data(int column) override;
	int      selfIndex() override;
	QString  getIcon() override;

	const QStringList & getActionsList() override;
	bool                runAction(const QString & arg) override;

private:
	/// \brief libname is the name of lib file
	QString libname;
};

}  // namespace icL::toolkit::session

#endif  // LIB_H
