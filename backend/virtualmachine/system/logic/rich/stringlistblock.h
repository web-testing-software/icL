#ifndef STRINGLISTBLOCK_H
#define STRINGLISTBLOCK_H

#include "../main/richblock.h"



namespace vm {
namespace system {
namespace logic {
namespace rich {

class StringListBlock : public RichBlock
{
public:
	StringListBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

private:
	static QStringList varNameToValue (const QString &varname);
	static bool operatorEqual (const QStringList &list1, const QStringList &list2);

	static QRegExp exp;
	static QRegularExpression strExp;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // STRINGLISTBLOCK_H
