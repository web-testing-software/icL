#include "type.h"

namespace vm::memory {

QString typeToString(Type type) {
	QString ret;

	switch (type) {
	case Type::Void:
		ret = "Void";
		break;

	case Type::Boolean:
		ret = "Boolean";
		break;

	case Type::Int:
		ret = "Int";
		break;

	case Type::Double:
		ret = "Double";
		break;

	case Type::String:
		ret = "String";
		break;

	case Type::List:
		ret = "List";
		break;

	case Type::Element:
		ret = "Element";
		break;
	}

	return ret;
}



Type variantTypeToType(QVariant::Type type) {
	Type ret = Type::Void;

	switch (type) {
	case QVariant::Bool:
		ret = Type::Boolean;
		break;

	case QVariant::Int:
		ret = Type::Int;
		break;

	case QVariant::Double:
		ret = Type::Double;
		break;

	case QVariant::String:
		ret = Type::String;
		break;

	case QVariant::StringList:
		ret = Type::List;
		break;

	case QVariant::UserType:
		ret = Type::Element;
		break;

	default:
		break;
	}

	return ret;
}

}  // namespace vm::memory
