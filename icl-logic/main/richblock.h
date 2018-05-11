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
		Equal,
		NotEqual,
		Contains,
		ContainsFragment,
		Not,
		NotNot
	};

	RichBlock (OperationType otype);
	RichBlock (RichBlock *block);
	~RichBlock () override;

	bool canAcceptCode ();
	void giveCode (memory::CodeFragment frag);

	const OperationType& getOperationType () const;
	const QVariant& getValue1 () const;
	const QVariant& getValue2 () const;
	const memory::CodeFragment& getFrag1 () const;
	const memory::CodeFragment& getFrag2 () const;

protected:
	QString oTypeToString ();
	QString pairData ();
	void sendSignalWrongPair ();
	void sendSignalWrongOperator (const QString &pair);


protected:
	QVariant value1, value2;
	memory::CodeFragment frag1, frag2;
	bool valu1getted = false, value2getted = false;

	OperationType operationType;
	bool casted = false;

public:
	// LogicBlock interface
	bool isCross () override;
	bool checkIntegrity () override;

	bool needCast () override;
	LogicBlock* castNow () override;
	bool step () override;

	bool calcResult() override;
};

}

#endif // RICHBLOCK_H
