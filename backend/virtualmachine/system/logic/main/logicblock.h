#ifndef LOGICBLOCK_H
#define LOGICBLOCK_H



namespace vm {
namespace system {
namespace logic {

class LogicBlock
{
public:
	LogicBlock ();

	virtual bool getResult ()		= 0;
	virtual bool isCross ()			= 0;
	virtual bool checkIntegrity ()	= 0;

	LogicBlock* getParent ();
	void setParent (LogicBlock *parent);

private:
	LogicBlock *m_parent = nullptr;
};

}
}
}

#endif // LOGICBLOCK_H
