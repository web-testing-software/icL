#ifndef RICHBLOCK_H
#define RICHBLOCK_H

#include "../../main/virtualmachine.h"
#include "logicblock.h"

#include <QRegExp>
#include <QString>
#include <QVariant>



namespace vm {
namespace system {
namespace logic {

class RichBlock : public LogicBlock
{
public:
	enum class OperationType {
		EQUAL,
		NOT_EQUAL,
		CONTAINS,
		CONTAINS_FRAGMENT
	};

	RichBlock (OperationType otype);

	bool canAcceptVar ();
	void giveVar (QString &varname);

	// LogicBlock interface
	bool isCross () override;
	bool checkIntegrity () override;

protected:
	QString var1name;
	QString var2name;

	OperationType operationType;
};

}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // RICHBLOCK_H
