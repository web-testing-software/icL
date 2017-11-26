#include "stringblock.h"


vm::main::logic::rich::StringBlock::StringBlock (OperationType otype) :
	vm::main::logic::RichBlock (otype) {

}

QRegExp vm::main::logic::rich::StringBlock::exp = QRegExp ("\".*\"");

bool vm::main::logic::rich::StringBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool vm::main::logic::rich::StringBlock::calcResult () {
	bool	result	= false;
	QString var1	= varNameToString (var1name);
	QString var2	= varNameToString (var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = ( var1 == var2 );
		break;

	case OperationType::NOT_EQUAL :
		result = ( var1 != var2 );
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		drive->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands string:%1 and string:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

QString vm::main::logic::rich::StringBlock::varNameToString (const QString &varname) {
	DataState::Type type = DataState::Type::STRING;
	QString			ret;

	if (check (varname)) {
		ret = varname.mid (1, -2);
	}
	else if (!drive->checkType (varname, type)) {
		invalidate ();
		drive->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a string variable or constant.")
								  .arg (varname));
	}
	else {
		ret = drive->getVar (varname).toString ();
	}

	return ret;
}
