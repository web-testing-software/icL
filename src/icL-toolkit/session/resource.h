#ifndef RESOURCE_H
#define RESOURCE_H

#include "../tree/finaly.h"

#include <QString>



namespace icL::toolkit::session {

class Resource : tree::Finaly
{
public:
	Resource(Item * parent);

	// Item interface
public:
	int      columnCount() override;
	QVariant data(int column) override;
	int      selfIndex() override;
	QString  getIcon() override;

private:
	QString resurceName;
};

}  // namespace icL::toolkit::session

#endif  // RESOURCE_H
