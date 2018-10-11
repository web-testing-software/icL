#ifndef SCRIPT_H
#define SCRIPT_H

#include "../tree/finaly.h"

#include <QString>



namespace icL::toolkit::session {

class Script : public tree::Finaly
{
public:
	Script(Item * parent);

	// Item interface
public:
	int      columnCount() override;
	QVariant data(int column) override;
	int      selfIndex() override;
	QString  getIcon() override;

private:
	QString name;
};

}  // namespace icL::toolkit::session

#endif  // SCRIPT_H
