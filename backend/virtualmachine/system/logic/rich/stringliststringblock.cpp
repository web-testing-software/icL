#include "stringblock.h"
#include "stringlistblock.h"
#include "stringliststringblock.h"


vm::system::logic::rich::StringListStringBlock::StringListStringBlock (OperationType otype)
	: vm::system::logic::RichBlock (otype) {

}

bool vm::system::logic::rich::StringListStringBlock::calcResult()
{
	bool		result	= false;
	QStringList var1	= StringListBlock::varNameToValue (this, var1name);
	QString var2	= StringBlock::varNameToValue (this, var2name);

	switch (operationType) {
	case OperationType::CONTAINS :
		result = var1.contains (var2);
		break;

	case OperationType::CONTAINS_FRAGMENT :
		result = containsFragment (var1, var2);
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		virtualMachine->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands <string>list:%1 and string:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

bool vm::system::logic::rich::StringListStringBlock::containsFragment(const QStringList &strList, const QString &str)
{
	bool ret = false;

	for (const QString &strFromList : strList) {
		if (strFromList.indexOf (str) >= 0) {
			ret = true;
		}
	}

	return ret;
}
