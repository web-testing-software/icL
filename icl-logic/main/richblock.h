#ifndef RICHBLOCK_H
#define RICHBLOCK_H

//#include "../../main/virtualmachine.h"
#include "logicblock.h"

#include <QRegExp>
#include <QString>
#include <QVariant>



namespace vm::main::logic {

/**
 * @brief The RichBlock class - this class contains 2 variables or constants
 */
class RichBlock : public LogicBlock
{
public:
	enum class OperationType {
		EQUAL,
		NOT_EQUAL,
		CONTAINS,
		CONTAINS_FRAGMENT,
		NOT,
		NOT_NOT
	};

	RichBlock (OperationType otype);
	virtual ~RichBlock () override;

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

}

#endif // RICHBLOCK_H
