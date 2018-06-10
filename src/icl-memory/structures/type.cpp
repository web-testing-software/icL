#include "element.h"
#include "set.h"
#include "type.h"

namespace icL::memory {

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



Type variantTypeToType(const QVariant &var) {
	Type ret = Type::Void;

	switch (var.type()) {
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
		if (var.canConvert<ElementPtr>()) {
			ret = Type::Element;
		}
		else if (var.canConvert<SetPtr>()) {
			ret = Type::Set;
		}
		else if (var.canConvert<SetObjPtr>()) {
			ret = Type::SetObj;
		}
		break;

	default:
		break;
	}

	return ret;
}

}  // namespace icL::memory
