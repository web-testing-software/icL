#ifndef RICHBLOCK_H
#define RICHBLOCK_H

// #include "../../main/virtualmachine.h"
#include "logicblock.h"

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
	virtual ~RichBlock () override;

	bool canAcceptCode ();
	void giveCode (QString *code, int begin, int end);

	// LogicBlock interface
	bool isCross () override;
	bool checkIntegrity () override;

protected:
	QVariant value1, value2;
	QString *code1	= nullptr,
			*code2	= nullptr;
	int code1begin	= 0,
		code2begin	= 0;
	int code1end	= -1,
		code2end	= -1;

	OperationType operationType;
};

}

#endif // RICHBLOCK_H
