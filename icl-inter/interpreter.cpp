#include "interpreter.h"

#include <icl-context/base/object/boolean.h>
#include <icl-context/base/object/double.h>
#include <icl-context/base/object/int.h>
#include <icl-context/base/object/list.h>
#include <icl-context/base/object/string.h>
#include <icl-context/base/object/void.h>
#include <icl-context/complex/define.h>
#include <icl-context/complex/dom.h>
#include <icl-context/complex/log.h>
#include <icl-context/complex/tab.h>
#include <icl-context/control/control/catch/exists.h>
#include <icl-context/control/control/main/else.h>
#include <icl-context/control/control/main/if.h>
#include <icl-context/control/main/forany.h>
#include <icl-context/data/js/crossfire.h>
#include <icl-context/data/js/file.h>
#include <icl-context/data/js/get.h>
#include <icl-context/data/js/set.h>
#include <icl-context/data/main/alternative.h>
#include <icl-context/data/main/assign.h>
#include <icl-context/data/main/function.h>
#include <icl-context/data/main/method.h>
#include <icl-context/data/main/parameter.h>
#include <icl-context/data/main/property.h>

#include <utility>

namespace icL::inter {

Interpreter::Interpreter(memory::InterLevel * il)
	: memory::Node(il)
	, flayer(il) {}

context::Context * Interpreter::parseNext() {
	context::Context * ret       = nullptr;
	QChar              ch        = flayer.flyNextChar();
	int                begin_pos = flayer.getPosition() - 1, end_pos;

	if (ch.isLetter() && ch.isLower()) {
		ret = parseKeyword();
	}
	else {

		switch (ch.toLatin1()) {
		case ';':
		case ' ':
		case '\0':
			ret = nullptr;
			break;

		case '"':
			ret = parseString();
			break;

		case '#':
			ret = parseStateVar();
			break;

		case '@':
			ret = parseLocalVar();
			break;

		case '$':
			ret = parseJavascript();
			break;

		case 'E':
			ret = parseExist();
			break;

		case 'A':
			ret = parseAny();
			break;

		case '!':
			ret = parseFunction();
			break;

		case '-':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '6':
		case '7':
		case '8':
		case '9':
			ret = parseNumber();
			break;

		case '.':
			ret = parseProperty();
			break;

		case ':':
			ret = parseMethod();
			break;

		case '<':
			ret = parseParameter();
			break;

		case '=':
			ret = parseAssign();
			break;

		case '>':
			ret = parseConsole();
			break;

		case '[':
			ret = parseList();
			break;

		case '_':
			ret = parseSystemVar();
			break;

		case '{':
			ret = parseCode();
			break;

		case '|':
			ret = parseAlternative();
			break;

			//		case 'L':
			//			ret = parseLogic();
			//			break;

		default:
			il->vm->exception(
			  {-300, QStringLiteral(
					   "Unexpected token %1, expected one of next symbols "
					   ";\"#@$EA!-0123456789.:<=>[_{| or a keyword")
					   .arg(QString(ch))});
		}
	}

	if (ret != nullptr) {
		end_pos = flayer.getPosition() + 1;

		ret->setCursorPositions(begin_pos, end_pos);
	}

	return ret;
}

void Interpreter::newSignal(int code, const QString & name) {
	if (il->mem->signal_s().contains(name)) {
		il->vm->exception({-999, "Signal with this name alrready exists"});
		return;
	}

	il->mem->signal_s().insert(name, code);
}

Flayer & Interpreter::getFlayer() {
	return flayer;
}

context::Context * Interpreter::parseKeyword() {
	context::Context * ret;
	QString            keyword = flayer.flyKeyword();

	if (keyword == "if") {
		auto [frag, logic] = flayer.flyLogicFrag();
		ret                = new context::code::control::If{il, frag, logic};
	}
	else if (keyword == "else") {
		ret = new context::code::control::Else{il};
	}
	else if (keyword == "emitor") {
		il->vm->exception({-500, "system error"});
	}
	else if (keyword == "slot") {
		il->vm->exception({-500, "system error"});
	}
	else if (keyword == "emit") {
		il->vm->exception({-500, "system error"});
	}
	else if (keyword == "true") {
		ret = new context::object::Boolean{il, QVariant(true), true};
	}
	else if (keyword == "false") {
		ret = new context::object::Boolean{il, QVariant(false), true};
	}
	else {
		il->vm->exception(
		  {-300, QStringLiteral("Unknown keyword: %1").arg(keyword)});
	}

	return ret;
}

context::Context * Interpreter::parseString() {
	QString str = flayer.flyString();

	return new context::object::String{il, str, true};
}

context::Context * Interpreter::parseStateVar() {
	QString name = flayer.flyVarName();

	if (name.isEmpty()) {
		return new context::object::Void{il};
	}

	return context::Context::fromValue(il, il->mem->stateIt().state(), name);
}

context::Context * Interpreter::parseLocalVar() {
	QString name = flayer.flyVarName();

	if (name.isEmpty()) {
		name = "stack";
	}

	return context::Context::fromValue(
	  il, il->mem->stackIt().getContainer(name), name);
}

context::Context * Interpreter::parseJavascript() {
	QString            func = flayer.flyVarName();
	context::Context * res;


	if (func == "get") {
		res = new context::data::js::Get{il};
	}
	else if (func.isEmpty() || func == "set") {
		res = new context::data::js::Set{il};
	}
	else if (func == "file") {
		res = new context::data::js::File{il};
	}
	else if (func == "crossfire") {
		res = new context::data::js::Crossfire{il};
	}
	else {
		res = nullptr;

		il->vm->exception(
		  {-404, QStringLiteral("Function $%1 not found").arg(func)});
	}

	return res;
}

context::Context * Interpreter::parseExist() {
	auto codeFrag = flayer.flyAnyExistsFrag();

	return new context::code::control::catch0::Exists{il, codeFrag, false};
}

context::Context * Interpreter::parseAny() {
	auto codeFrag = flayer.flyAnyExistsFrag();

	return new context::code::ForAny{il, codeFrag};
}

context::Context * Interpreter::parseFunction() {
	QString name = flayer.flyVarName();

	if (name.isEmpty()) {
		il->vm->exception({-501, "Function name is empty"});
	}

	return new context::data::Function{il, name};
}

context::Context * Interpreter::parseNumber() {
	auto [pint, pdouble, is_int] = flayer.flyNumber();
	context::Context * res;

	if (is_int) {
		res = new context::object::Int{il, pint, true};
	}
	else {
		res = new context::object::Double{il, pdouble, true};
	}

	return res;
}

context::Context * Interpreter::parseProperty() {
	auto [prefix, name] = flayer.flyProperty();

	return new context::data::Property{il, prefix, name};
}

context::Context * Interpreter::parseMethod() {
	QString name = flayer.flyVarName();

	if (name.isEmpty()) {
		il->vm->exception({-501, "Method name is empty"});
	}

	return new context::data::Method{il, name};
}

context::Context * Interpreter::parseParameter() {
	QString      type = flayer.flyVarName(), name;
	QChar        ch;
	memory::Type mtype = memory::Type::Void;

	if (type.isEmpty()) {
		il->vm->exception({-501, "Parameter type is empty"});
	}

	ch = flayer.flyNextChar();
	if (ch != '>') {
		il->vm->exception(
		  {-502, QStringLiteral("Unexpected %1, expected >").arg(ch)});
	}

	name = flayer.flyVarName();

	if (name.isEmpty()) {
		il->vm->exception({-501, "Parameter name is empty"});
	}

	if (type == "Boolean") {
		mtype = memory::Type::Boolean;
	}
	else if (type == "Int") {
		mtype = memory::Type::Int;
	}
	else if (type == "Double") {
		mtype = memory::Type::Double;
	}
	else if (type == "String") {
		mtype = memory::Type::String;
	}
	else if (type == "List") {
		mtype = memory::Type::List;
	}
	else if (type == "Element") {
		mtype = memory::Type::Element;
	}
	else {
		il->vm->exception(
		  {-502,
		   QStringLiteral(
			 "unexpected %1, expected Int, Double, String, List or Element")
			 .arg(type)});
	}

	return new context::data::Parameter{il, name, mtype};
}

context::Context * Interpreter::parseAssign() {
	return new context::data::Assign{il};
}

context::Context * Interpreter::parseConsole() {
	il->vm->exception({-500, "system error"});

	return nullptr;
}

context::Context * Interpreter::parseList() {
	QChar ch = flayer.flyNextChar();

	if (ch == ']') {
		return new context::object::List{il, QStringList{}, true};
	}

	il->vm->exception({-500, "system error"});

	return nullptr;
}

context::Context * Interpreter::parseSystemVar() {
	QString            name = flayer.flyVarName();
	context::Context * ret  = nullptr;

	if (name == "dom") {
		ret = new context::complex::Dom{il};
	}
	else if (name == "log") {
		ret = new context::complex::Log{il};
	}
	else if (name == "define") {
		ret = new context::complex::Define{il};
	}
	else if (name == "tab") {
		ret = new context::complex::Tab{il};
	}

	else {
		il->vm->exception(
		  {-502, QStringLiteral("unexpected %1, expected dom, log, define, tab")
				   .arg(name)});
	}

	return ret;
}

context::Context * Interpreter::parseCode() {
	auto code = flayer.flyCode();

	return new context::code::Code{il, code};
}

context::Context * Interpreter::parseAlternative() {
	return new context::data::Alternative{il};
}



}  // namespace icL::inter
