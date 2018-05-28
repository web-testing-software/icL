#ifndef icL_logic_rich_Rich
#define icL_logic_rich_Rich

#include "logic.h"

#include <icl-memory/structures/functioncontainer.h>

#include <QRegExp>
#include <QString>
#include <QVariant>


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |-> logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::logic::rich {

/**
 * @brief The Rich class - this class contains 2 variables or constants
 */
class Rich : public Logic
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

	Rich(memory::InterLevel * il, OperationType otype);
	Rich(memory::InterLevel * il, Rich * block);
	~Rich() override;

	bool canAcceptCode();
	void giveCode(memory::CodeFragment frag);

	const OperationType &        getOperationType() const;
	const QVariant &             getValue1() const;
	const QVariant &             getValue2() const;
	const memory::CodeFragment & getFrag1() const;
	const memory::CodeFragment & getFrag2() const;

protected:
	QString oTypeToString();
	QString pairData();
	void    sendSignalWrongPair();
	void    sendSignalWrongOperator(const QString & pair);


protected:
	QVariant             value1, value2;
	memory::CodeFragment frag1, frag2;
	bool                 valu1getted = false, value2getted = false;

	OperationType operationType;
	bool          casted = false;

public:
	// Logic interface
	bool isCross() override;
	bool checkIntegrity() override;

	bool         needCast() override;
	Logic * castNow() override;
	bool         step() override;

	bool calcResult() override;
};

}  // namespace icL::logic

#endif  // icL_logic_rich_Rich
