#include "stringliststringblock.h"

namespace vm::main::logic::rich {

StringListStringBlock::StringListStringBlock (OperationType otype)
	: StringListBlock (otype) {

}

bool StringListStringBlock::calcResult () {
	bool		result	= false;
	QStringList var1	= varNameToStringList (var1name);
	QString		var2	= varNameToString (var2name);

//	StringListBlock::varNameToStringList ("sd");
//	static_cast<StringListBlock*>(this)

	switch (operationType) {
	case OperationType::CONTAINS :
		result = var1.contains (var2);
		break;

	case OperationType::CONTAINS_FRAGMENT :
		result = containsFragment (var1, var2);
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		dataContainer->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands <string>list:%1 and string:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

bool StringListStringBlock::containsFragment (const QStringList &strList, const QString &str) {
	bool ret = false;

	for (const QString &strFromList : strList) {
		if (strFromList.indexOf (str) >= 0) {
			ret = true;
		}
	}

	return ret;
}

}
