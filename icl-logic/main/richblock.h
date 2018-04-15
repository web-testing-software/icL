#ifndef RICHBLOCK_H
#define RICHBLOCK_H

// #include "../../main/virtualmachine.h"
#include "logicblock.h"

#include "icl-memory/structures/functioncontainer.h"

#include <QRegExp>
#include <QString>
#include <QVariant>



namespace vm::logic {

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
	 ~RichBlock () override;

	bool canAcceptCode ();
	void giveCode (memory::CodeFragment frag);

	// LogicBlock interface
	bool isCross () override;
	bool checkIntegrity () override;

protected:
	QVariant value1, value2;
	memory::CodeFragment frag1, frag2;

	OperationType operationType;
	bool casted = false;
};

}

#endif // RICHBLOCK_H
