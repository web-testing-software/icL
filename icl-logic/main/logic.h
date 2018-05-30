#ifndef icL_logic_Logic
#define icL_logic_Logic

#include <icl-memory/interlevel/node.h>
#include <icl-memory/state/memory.h>
#include <icl-memory/structures/exception.h>
#include <icl-memory/structures/return.h>

#include <QObject>

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
 * @brief The Logic class
 */
class Logic : public memory::Node
{
public:
	Logic(memory::InterLevel * il);
	virtual ~Logic() = default;

	bool         getResult();
	bool         getCachedResult();
	virtual bool isCross()        = 0;
	virtual bool checkIntegrity() = 0;
	virtual void resetResultValue();
	void         invalidate();

	virtual bool         needCast() = 0;
	virtual Logic * castNow()  = 0;
	virtual bool         step()     = 0;
	virtual bool         canResultPreliminarily();

	Logic * getParent();
	void         setParent(Logic * parent);

protected:
	virtual bool calcResult() = 0;

	static QString typeToString(QVariant::Type type);


protected:
	icL::memory::Memory * m_memory;

	ResultValue resultValue = ResultValue::NOT_CALCULATED;
	bool        ready1 = false, ready2 = false;
	bool        resultCalculed = false, result = false;

private:
	Logic * m_parent = nullptr;
};

}  // namespace icL::logic

#endif  // icL_logic_Logic
