#include "interpreter.h"

#include <icl-context/base/object/boolean.h>
#include <icl-context/control/control/main/else.h>
#include <icl-context/control/control/main/if.h>

#include <utility>

namespace icL::inter {

Interpreter::Interpreter(memory::InterLevel * il, const QString * source)
	: memory::Node(il)
	, flayer({il, source}) {}

context::Context * Interpreter::parseNext() {
	context::Context * ret = nullptr;
	QChar              ch  = flayer.getNextChar();

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

	return ret;
}

context::Context * Interpreter::parseKeyword() {
	context::Context * ret;
	QString            keyword = flayer.getKeyword();

	if (keyword == "if") {
		auto [frag, logic] = flayer.getLogicFrag();
		ret                = new context::code::control::If{il, frag, logic};
	}
	else if (keyword == "else") {
		ret = new context::code::control::Else{il};
	}
	else if (keyword == "emitor") {
		il->vm->exception({-300, "system error"});
	}
	else if (keyword == "slot") {
		il->vm->exception({-300, "system error"});
	}
	else if (keyword == "emit") {
		il->vm->exception({-300, "system error"});
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

context::Context * Interpreter::parseString() {}

context::Context * Interpreter::parseStateVar() {}

context::Context * Interpreter::parseLocalVar() {}

context::Context * Interpreter::parseJavascript() {}

context::Context * Interpreter::parseExist() {}

context::Context * Interpreter::parseAny() {}

context::Context * Interpreter::parseFunction() {}

context::Context * Interpreter::parseNumber() {}

context::Context * Interpreter::parseProperty() {}

context::Context * Interpreter::parseMethod() {}

context::Context * Interpreter::parseParameter() {}

context::Context * Interpreter::parseAssign() {}

context::Context * Interpreter::parseConsole() {}

context::Context * Interpreter::parseList() {}

context::Context * Interpreter::parseSystemVar() {}

context::Context * Interpreter::parseCode() {}

context::Context * Interpreter::parseAlternative() {}

context::Context * Interpreter::parseLogic() {}



}  // namespace icL::inter
