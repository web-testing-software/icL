#ifndef STRINGLISTBLOCK_H
#define STRINGLISTBLOCK_H

#include "../main/richblock.h"

#include "stringblock.h"



namespace vm {
namespace main {
namespace logic {
namespace rich {

class StringListBlock : public StringBlock
{
public:
	StringListBlock (OperationType otype);

	static bool check (const QString &value);

	// LogicBlock interface
	bool calcResult () override;

protected:
	QStringList varNameToStringList (const QString &varname);

private:
	static bool operatorEqual (const QStringList &list1, const QStringList &list2);

	static QRegExp exp;
	static QRegularExpression strExp;
};

}   // namespace rich
}   // namespace logic
}   // namespace system
}   // namespace vm

#endif // STRINGLISTBLOCK_H
