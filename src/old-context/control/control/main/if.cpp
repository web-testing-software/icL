#include "if.h"

#include <icl-logic/cross/and.h>
#include <icl-logic/cross/eq.h>
#include <icl-logic/cross/or.h>
#include <icl-logic/cross/xor.h>
#include <icl-logic/main/cross.h>
#include <icl-logic/main/logic.h>
#include <icl-logic/rich/single.h>

#include <QDebug>

namespace old::context::code::control {


If::If(
  memory::InterLevel * il, const memory::CodeFragment & source, bool expExe)
    : Control(il, source)
    , isLogicExp(expExe) {
	m_role = Role::If;
}

If::~If() {
	if (exp != nullptr) {
		delete exp;
	}
}

void If::parseLogicExp() {
	if (isLogicExp) {
		exp = parseOnce(m_source);
	}
	else {
		auto * single =
		  new logic::rich::Single{il, logic::rich::Rich::OperationType::NotNot};

		single->giveCode(m_source);
		exp = single;
	}
}

// The brackets pairs must be checked first, by interpreteur
logic::Logic * If::parseOnce(memory::CodeFragment & fn) {
	Operator        op;
	const QString * str = fn.source;
	QString         brackets;

	if (fn.end == fn.begin) {
		il->vm->exception({-201, "Empty operand detected."});
		return nullptr;
	}

	op.type = OperatorType::NotFound;
	op.rank = 0;
	brackets.reserve(32);


	for (int i = fn.begin; i < fn.end; i++) {

		if (brackets.endsWith('"')) {
			if (str->at(i) == '\\') {
				i++;
			}
			else if (str->at(i) == '"') {
				brackets.chop(1);
			}
		}
		else {
			switch (str->at(i).toLatin1()) {

			case '(':
				brackets.append('(');
				break;

			case '[':
				brackets.append('[');
				break;

			case '"':
				brackets.append('"');
				break;

			case ')':
			case ']':
				brackets.chop(1);
				break;

			case '!':
				processNots(op, str->at(i + 1), i);
				break;

			case '=':
				processEquals(op, str->at(i + 1), i);
				break;

			case '<':
				processContains(op, str->at(i + 1), i);
				break;

			case '&':
				makeRank3(op, OperatorType::And, i);
				break;

			case '|':
				makeRank3(op, OperatorType::Or, i);
				break;

			case '^':
				makeRank3(op, OperatorType::XOr, i);
				break;

			case '~':
				makeRank3(op, OperatorType::Equiv, i);
				break;
			}
		}
	}

	if (op.type == OperatorType::NotFound) {
		auto * single =
		  new logic::rich::Single{il, logic::rich::Rich::OperationType::NotNot};

		single->giveCode(fn);
		return single;
	}
	else {
		if (op.rank == 1) {
			return returnRank1(op, fn);
		}
		else if (op.rank == 2) {
			return returnRank2(op, fn);
		}
		else if (op.rank == 3) {
			return returnRank3(op, fn);
		}
		else {
			// Never triggered
			qDebug() << "Fatal error in If.parseOnce";
			return nullptr;
		}
	}
}

void If::makeRank3(Operator & op, OperatorType type, int i) {
	if (op.rank < 3) {
		op.type     = type;
		op.rank     = 3;
		op.position = i;
	}
}

void If::processNots(Operator & op, const QChar & next, int & i) {
	if (next == '=' && op.rank < 2) {
		op.type     = OperatorType::NotEqual;
		op.rank     = 2;
		op.position = i++;
	}
	else if (!next.isLetter() && op.rank < 1) {
		op.type     = next == '!' ? OperatorType::NotNot : OperatorType::Not;
		op.rank     = 1;
		op.position = i++;
	}
}

void If::processEquals(Operator & op, const QChar & next, int & i) {
	if (next == '=' && op.rank < 2) {
		op.type     = OperatorType::Equal;
		op.rank     = 2;
		op.position = i++;
	}
}

void If::processContains(Operator & op, const QChar & next, int & i) {
	if ((next == '<' || next == '=') && op.rank < 2) {
		op.type =
		  next == '<' ? OperatorType::Contains : OperatorType::ContainsFragment;
		op.rank     = 2;
		op.position = i;
	}
}

void If::filter(memory::CodeFragment fn) {
	bool ready = false;

	do {
		while (fn.begin < fn.end) {
			QChar ch = fn.source->at(fn.begin);

			if (ch == ' ' || ch == '\t' || ch == '\n') {
				fn.begin++;
			}
			else {
				break;
			}
		}

		while (fn.end > fn.begin) {
			QChar ch = fn.source->at(fn.end - 1);

			if (ch == ' ' || ch == '\t' || ch == '\n') {
				fn.end--;
			}
			else {
				break;
			}
		}

		if (fn.end == fn.begin) {
			il->vm->exception({-201, "Empty operand detected."});
		}

		if (
		  fn.source->at(fn.begin) == '(' && fn.source->at(fn.end - 1) == ')') {
			for (int i = fn.begin, rank = 0; i < fn.end; i++) {
				if (fn.source->at(i) == '(') {
					rank++;
				}
				else if (fn.source->at(i) == ')') {
					rank--;

					if (rank == 0 && i != fn.end - 1) {
						ready = true;
					}
				}
			}

			if (!ready) {
				fn.begin++;
				fn.end--;
			}
		}
		else {
			ready = true;
		}
	} while (!ready);
}

logic::Logic * If::returnRank1(Operator & op, memory::CodeFragment & fn) {
	bool isOk = true;

	for (int i = fn.begin; i < op.position; i++) {
		QChar ch = fn.source->at(i);
		isOk &= ch == '\n' || ch == '\t' || ch == ' ';
	}

	if (!isOk) {
		il->vm->exception(
		  {-201,
		   QString(
		     "Rank 1 operators (! and !!) givis one operand, placed on right. "
		     "Parsing failed for `%1`")
		     .arg(fn.source->midRef(fn.begin, fn.end - fn.begin))});
		return nullptr;
	}

	memory::CodeFragment newfn  = fn;
	auto *               single = new logic::rich::Single(
      il, op.type == OperatorType::Not
            ? logic::rich::Rich::OperationType::Not
            : logic::rich::Rich::OperationType::NotNot);

	newfn.begin += op.type == OperatorType::Not ? 1 : 2;
	filter(newfn);

	single->giveCode(newfn);
	return single;
}

logic::Logic * If::returnRank2(Operator & op, memory::CodeFragment & fn) {
	memory::CodeFragment newfn1 = fn, newfn2 = fn;

	newfn1.end = op.position;
	newfn2.begin =
	  op.position + 2;  // All rank 2 operators consist of 2 symbols

	filter(newfn1);
	filter(newfn2);

	logic::rich::Rich::OperationType type;

	switch (op.type) {
	case OperatorType::Equal:
		type = logic::rich::Rich::OperationType::Equal;
		break;

	case OperatorType::NotEqual:
		type = logic::rich::Rich::OperationType::NotEqual;
		break;

	case OperatorType::Contains:
		type = logic::rich::Rich::OperationType::Contains;
		break;

	case OperatorType::ContainsFragment:
		type = logic::rich::Rich::OperationType::ContainsFragment;
		break;

	default:
		// Never triggered, elude clang warning
		type = logic::rich::Rich::OperationType::NotNot;
		break;
	}

	auto * block = new logic::rich::Rich{il, type};

	block->giveCode(newfn1);
	block->giveCode(newfn2);

	return block;
}

logic::Logic * If::returnRank3(Operator & op, memory::CodeFragment & fn) {
	memory::CodeFragment newfn1 = fn, newfn2 = fn;

	newfn1.end   = op.position;
	newfn2.begin = op.position + 1;  // All rank 2 operators consist of 1 symbol

	filter(newfn1);
	filter(newfn2);

	logic::cross::Cross * block;

	switch (op.type) {
	case OperatorType::And:
		block = new logic::cross::And{il};
		break;

	case OperatorType::Or:
		block = new logic::cross::Or{il};
		break;

	case OperatorType::XOr:
		block = new logic::cross::XOr{il};
		break;

	case OperatorType::Equiv:
		block = new logic::cross::Eq{il};
		break;

	default:
		// Never triggered, elude clang warning
		block = nullptr;
	}

	block->giveBlock(parseOnce(newfn1));
	block->giveBlock(parseOnce(newfn2));

	return block;
};



bool If::checkPrev(const Context * context) const {
	return context == nullptr || context->role() == Role::Else;
}

bool If::isExecutable() const {
	return !expressionExecuted || result;
}

memory::StepType::Value If::execute() {
	if (exp == nullptr) {
		parseLogicExp();

		il->vms->setSColor(memory::SelectionColor::Parsing);
		il->vms->highlight(m_source.begin - 1, m_source.end + 1);
	}
	else if (!expressionExecuted) {
		if (exp->needCast()) {
			logic::Logic * new_exp = exp->castNow();

			delete exp;
			exp = new_exp;
		}
		else if (exp->step()) {
			expressionExecuted = true;
			result             = exp->getCachedResult();

			il->vms->setSColor(memory::SelectionColor::Executing);
			il->vms->highlight(beginCursorPosition, endCursorPostion);
		}
	}
	else {
		// The next always will be a code block
		return m_next->execute();
	}

	return memory::StepType::CommandIn;
}

Context * If::getBeginContext() {
	return getFirst();
}

Context * If::getEndContext() {
	return getLast();
}

}  // namespace old::context::code::control
