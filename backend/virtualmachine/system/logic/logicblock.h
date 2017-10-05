#ifndef LOGICBLOCK_H
#define LOGICBLOCK_H



namespace vm {
namespace system {
namespace logic {

class LogicBlock
{
public:
	LogicBlock ();

	virtual bool getResult ()	= 0;
	virtual bool isCross ()		= 0;
};

}
}
}

#endif // LOGICBLOCK_H
