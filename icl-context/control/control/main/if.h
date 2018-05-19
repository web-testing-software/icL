#ifndef icL_context_code_control_If
#define icL_context_code_control_If

#include "control.h"

namespace icL::logic {
class Logic;
}


/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- @namespace control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::code::control {

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
	If(memory::InterLevel * il, const memory::CodeFragment & source, bool expExe);
	~If();

protected:
	void parseLogicExp();

	logic::Logic * parseOnce(memory::CodeFragment & fn);

	void makeRank3(Operator & op, OperatorType type, int i);
	void processNots(Operator & op, const QChar & next, int i);
	void processEquals(Operator & op, const QChar & next, int i);
	void processContains(Operator & op, const QChar & next, int i);

	void filter(memory::CodeFragment fn);

	logic::Logic * returnRank1(Operator & op, memory::CodeFragment & fn);
	logic::Logic * returnRank2(Operator & op, memory::CodeFragment & fn);
	logic::Logic * returnRank3(Operator & op, memory::CodeFragment & fn);

protected:
	bool isLogicExp;

	bool                expressionExecuted = false;
	logic::Logic * exp                = nullptr;
	bool                result             = false;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool isExecuable() const override;
	bool execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace icL::context::code::control

#endif  // icL_context_code_control_If
