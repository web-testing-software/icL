#ifndef LOGICBLOCK_H
#define LOGICBLOCK_H

#include "../../icl-memory/state/datacontainer.h"

namespace vm::main::logic {

/**
 * @brief The LogicBlock class
 */
class LogicBlock
{
public:
	// Specially for debug mode
	enum class ResultValue {
		NOT_CALCULATED,
		INTEGRITY_CHECK_FAILED,
		WRONG_INPUT_DATA,
		TRUE_VALUE,
		FALSE_VALUE,
		FAILED_CALCULATE
	};

	LogicBlock ();
	virtual ~LogicBlock ();

	bool getResult ();
	virtual bool isCross ()			= 0;
	virtual bool checkIntegrity ()	= 0;
	virtual void resetResultValue ();
	void invalidate ();

	LogicBlock* getParent ();
	void setParent (LogicBlock *parent);

protected:
	virtual bool calcResult () = 0;

	vm::memory::DataContainer *dataContainer;
	ResultValue resultValue = ResultValue::NOT_CALCULATED;

private:
	LogicBlock *m_parent = nullptr;
};

}

#endif // LOGICBLOCK_H
