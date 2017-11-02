#ifndef LOGICBLOCK_H
#define LOGICBLOCK_H



namespace vm {
namespace system {
namespace logic {

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

	bool getResult ();
	virtual bool isCross ()			= 0;
	virtual bool checkIntegrity ()	= 0;
	virtual void resetResultValue ();
	void invalidate ();

	LogicBlock* getParent ();
	void setParent (LogicBlock *parent);

protected:
	virtual bool calcResult () = 0;

	ResultValue resultValue = ResultValue::NOT_CALCULATED;

private:
	LogicBlock *m_parent = nullptr;
};

}
}
}

#endif // LOGICBLOCK_H
