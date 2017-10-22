#ifndef STRINGBLOCK_H
#define STRINGBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class StringBlock : public RichBlock
{
public:
	StringBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

private:
	static QString varNameToValue (const QString &varname);

	static QRegExp exp;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // STRINGBLOCK_H
