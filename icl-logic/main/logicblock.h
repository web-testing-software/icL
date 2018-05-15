#ifndef LOGICBLOCK_H
#define LOGICBLOCK_H

#include <icl-memory/state/memory.h>
#include <icl-memory/structures/exception.h>
#include <icl-memory/structures/return.h>

#include <QObject>

/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- @namespace logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::logic {

// Specially for debug mode
enum class ResultValue {
	NOT_CALCULATED,
	INTEGRITY_CHECK_FAILED,
	WRONG_INPUT_DATA,
	TRUE_VALUE,
	FALSE_VALUE,
	FAILED_CALCULATE
};

/**
 * @brief The LogicBlock class
 */
class LogicBlock
{
public:
	LogicBlock();
	virtual ~LogicBlock();

	bool         getResult();
	bool         getCachedResult();
	virtual bool isCross()        = 0;
	virtual bool checkIntegrity() = 0;
	virtual void resetResultValue();
	void         invalidate();

	virtual bool         needCast() = 0;
	virtual LogicBlock * castNow()  = 0;
	virtual bool         step()     = 0;
	virtual bool         canResultPreliminarily();

	LogicBlock * getParent();
	void         setParent(LogicBlock * parent);

signals:
	void exception(memory::Exception exc);
	void interrupt(memory::FunctionCall, std::function<void(memory::Return &)>);

protected:
	virtual bool calcResult() = 0;

	static QString typeToString(QVariant::Type type);


protected:
	icL::memory::Memory * m_memory;

	ResultValue resultValue = ResultValue::NOT_CALCULATED;
	bool        ready1 = false, ready2 = false;
	bool        resultCalculed = false, result = false;

private:
	LogicBlock * m_parent = nullptr;
};

}  // namespace icL::logic

#endif  // LOGICBLOCK_H
