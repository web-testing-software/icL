#ifndef LIB_H
#define LIB_H

#include "../tree/finaly.h"

#include <QString>



namespace icL::toolkit::session {

class Lib : public tree::Finaly
{
public:
	Lib(Item * parent);

	bool setPath(const QString & path);

	// Item interface
public:
	int      columnCount() override;
	QVariant data(int column) override;
	int      selfIndex() override;
	QString  getIcon() override;

private:
	QString libname;
};

}  // namespace icL::toolkit::session

#endif  // LIB_H
