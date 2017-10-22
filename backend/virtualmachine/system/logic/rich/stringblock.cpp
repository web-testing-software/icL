#include "stringblock.h"


vm::system::logic::rich::StringBlock::StringBlock (OperationType otype) :
	vm::system::logic::RichBlock (otype) {

}

QRegExp vm::system::logic::rich::StringBlock::exp = QRegExp ("\".*\"");

bool vm::system::logic::rich::StringBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool vm::system::logic::rich::StringBlock::calcResult () {
	bool	result	= false;
	QString var1	= varNameToValue (this, var1name);
	QString var2	= varNameToValue (this, var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = ( var1 == var2 );
		break;

	case OperationType::NOT_EQUAL :
		result = ( var1 != var2 );
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		virtualMachine->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands string:%1 and string:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

QString vm::system::logic::rich::StringBlock::varNameToValue (LogicBlock *block, const QString &varname) {
	DataState::Type type = DataState::Type::STRING;
	QString			ret;

	if (check (varname)) {
		ret = varname.mid (1, -2);
	}
	else if (!virtualMachine->checkType (varname, type)) {
		block->invalidate ();
		virtualMachine->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a string variable or constant.")
								  .arg (varname));
	}
	else {
		ret = virtualMachine->getVar (varname).toString ();
	}

	return ret;
}
