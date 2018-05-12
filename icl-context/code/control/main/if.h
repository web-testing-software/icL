#ifndef IF_H
#define IF_H

#include "control.h"

namespace vm::logic {
class LogicBlock;
}

namespace vm::context::code::control {

enum class OperatorType {
	NotFound,
	Equal,
	NotEqual,
	Contains,
	ContainsFragment,
	Not,
	NotNot,
	And,
	Or,
	XOr,
	Equiv
};

struct Operator
{
	int          position;
	OperatorType type;
	uint8_t      rank;
};

class If : public Control
{
public:
	If(const memory::CodeFragment& source, bool expExe);
	~If();

protected:
	void parseLogicExp();

	logic::LogicBlock* parseOnce(memory::CodeFragment& fn);

	void makeRank3(Operator& op, OperatorType type, int i);
	void processNots(Operator& op, const QChar& next, int i);
	void processEquals(Operator& op, const QChar& next, int i);
	void processContains(Operator& op, const QChar& next, int i);

	void filter(memory::CodeFragment fn);

	logic::LogicBlock* returnRank1(Operator& op, memory::CodeFragment& fn);
	logic::LogicBlock* returnRank2(Operator& op, memory::CodeFragment& fn);
	logic::LogicBlock* returnRank3(Operator& op, memory::CodeFragment& fn);

protected:
	bool isLogicExp;

	bool               expressionExecuted = false;
	logic::LogicBlock* exp                = nullptr;
	bool               result             = false;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;
};

}  // namespace vm::context::code::control

#endif  // IF_H
