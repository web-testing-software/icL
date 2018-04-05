#ifndef LOGICBLOCK_H
#define LOGICBLOCK_H

#include <QObject>

#include "icl-memory/state/datacontainer.h"


namespace vm::logic {

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
	bool getCachedResult ();
	virtual bool isCross ()			= 0;
	virtual bool checkIntegrity ()	= 0;
	virtual void resetResultValue ();
	void invalidate ();

	virtual bool step () = 0;

	LogicBlock* getParent ();
	void setParent (LogicBlock *parent);

signals:
	void interrupt (QString*, int, int, std::function<void (QVariant&)>);

protected:
	virtual bool calcResult () = 0;

	vm::memory::DataContainer *dataContainer;
	ResultValue resultValue = ResultValue::NOT_CALCULATED;
	bool ready1 = false, ready2 = false;
	bool resultCalculed = false, result = false;

private:
	LogicBlock *m_parent = nullptr;
};

}

#endif // LOGICBLOCK_H
