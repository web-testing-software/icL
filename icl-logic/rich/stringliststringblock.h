#ifndef STRINGLISTSTRINGBLOCK_H
#define STRINGLISTSTRINGBLOCK_H

#include "../main/richblock.h"
#include "stringblock.h"
#include "stringlistblock.h"

namespace vm::main::logic::rich {

/**
 * @brief The StringListStringBlock class - search a <string> in <string>list
 */
class StringListStringBlock : public StringListBlock
{
public:
	StringListStringBlock (OperationType otype);

	// LogicBlock interface
protected:
	bool calcResult () override;

private:
	bool containsFragment (const QStringList &strList, const QString &str);
};

}

#endif // STRINGLISTSTRINGBLOCK_H
