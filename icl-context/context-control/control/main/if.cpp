#include "if.h"

#include <icl-logic/cross/andblock.h>
#include <icl-logic/cross/eqblock.h>
#include <icl-logic/cross/orblock.h>
#include <icl-logic/cross/xorblock.h>
#include <icl-logic/main/crossblock.h>
#include <icl-logic/main/logicblock.h>
#include <icl-logic/rich/singleblock.h>

#include <QDebug>

namespace icL::context::code::control {


If::If(
  memory::InterLevel * il, const memory::CodeFragment & source, bool expExe)
	: Control(il, source)
	, expressionExecuted(expExe) {
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
		  new logic::rich::SingleBlock{logic::RichBlock::OperationType::NotNot};

		single->giveCode(m_source);
		exp = single;
	}
}

// The brackets pairs must be checked first, by interpreteur
logic::LogicBlock * If::parseOnce(memory::CodeFragment & fn) {
	Operator  op;
	QString * str = fn.source;
	QString   brackets;

	if (fn.end == fn.begin) {
		emit exception({-201, "Empty operand detected."});
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
				str->chop(1);
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
		  new logic::rich::SingleBlock{logic::RichBlock::OperationType::NotNot};

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

void If::processNots(Operator & op, const QChar & next, int i) {
	if (next == '=' && op.rank < 2) {
		op.type     = OperatorType::NotEqual;
		op.rank     = 2;
		op.position = i;
	}
	else if (!next.isLetter() && op.rank < 1) {
		op.type     = next == '!' ? OperatorType::NotNot : OperatorType::Not;
		op.rank     = 1;
		op.position = i;
	}
}

void If::processEquals(Operator & op, const QChar & next, int i) {
	if (next == '=' && op.rank < 2) {
		op.type     = OperatorType::Equal;
		op.rank     = 1;
		op.position = i;
	}
}

void If::processContains(Operator & op, const QChar & next, int i) {
	if ((next == '<' || next == '=') && op.rank < 2) {
		op.type =
		  next == '<' ? OperatorType::Contains : OperatorType::ContainsFragment;
		op.rank     = 2;
		op.position = i;
	}
}

/**
 * @brief If::filter - remove useless symbils at end and begin of source
 * @param fn - function, it source will be filter
 * @example " #a == #b \t " -> "#a == #b"
 * @example " ((( ( ((  ( #a == #b ) )) )  )))" -> "#a == #b"
 */
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
			emit exception({-201, "Empty operand detected."});
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
	} while (!ready);
}

logic::LogicBlock * If::returnRank1(Operator & op, memory::CodeFragment & fn) {
	bool isOk = true;

	for (int i = fn.begin; i < op.position; i++) {
		QChar ch = fn.source->at(i);
		isOk &= ch == '\n' || ch == '\t' || ch == ' ';
	}

	if (!isOk) {
		emit exception(
		  {-201,
		   QString(
			 "Rank 1 operators (! and !!) givis one operand, placed on right. "
			 "Parsing failed for `%1`")
			 .arg(fn.source->midRef(fn.begin, fn.end - fn.begin))});
		return nullptr;
	}

	memory::CodeFragment newfn  = fn;
	auto *               single = new logic::rich::SingleBlock(
	  op.type == OperatorType::Not ? logic::RichBlock::OperationType::Not
								   : logic::RichBlock::OperationType::NotNot);

	newfn.begin += op.type == OperatorType::Not ? 1 : 2;
	filter(newfn);

	single->giveCode(newfn);
	return single;
}

logic::LogicBlock * If::returnRank2(Operator & op, memory::CodeFragment & fn) {
	memory::CodeFragment newfn1 = fn, newfn2 = fn;

	newfn1.end = op.position;
	newfn2.begin =
	  op.position + 2;  // All rank 2 operators consist of 2 symbols

	filter(newfn1);
	filter(newfn2);

	logic::RichBlock::OperationType type;

	switch (op.type) {
	case OperatorType::Equal:
		type = logic::RichBlock::OperationType::Equal;
		break;

	case OperatorType::NotEqual:
		type = logic::RichBlock::OperationType::NotEqual;
		break;

	case OperatorType::Contains:
		type = logic::RichBlock::OperationType::Contains;
		break;

	case OperatorType::ContainsFragment:
		type = logic::RichBlock::OperationType::ContainsFragment;
		break;

	default:
		// Never triggered, elude clang warning
		type = logic::RichBlock::OperationType::NotNot;
		break;
	}

	auto * block = new logic::RichBlock{type};

	block->giveCode(newfn1);
	block->giveCode(newfn2);

	return block;
}

logic::LogicBlock * If::returnRank3(Operator & op, memory::CodeFragment & fn) {
	memory::CodeFragment newfn1 = fn, newfn2 = fn;

	newfn1.end   = op.position;
	newfn2.begin = op.position + 1;  // All rank 2 operators consist of 1 symbol

	filter(newfn1);
	filter(newfn2);

	logic::CrossBlock * block;

	switch (op.type) {
	case OperatorType::And:
		block = new logic::cross::AndBlock;
		break;

	case OperatorType::Or:
		block = new logic::cross::OrBlock;
		break;

	case OperatorType::XOr:
		block = new logic::cross::XOrBlock;
		break;

	case OperatorType::Equiv:
		block = new logic::cross::EqBlock;
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

bool If::isExecuable() const {
	return !expressionExecuted || result;
}

bool If::execute() {
	if (exp == nullptr) {
		parseLogicExp();
	}
	else if (!expressionExecuted) {
		if (exp->step()) {
			expressionExecuted = true;
			result             = exp->getCachedResult();
		}
	}
	else {
		// The next always will be a code block
		return m_next->execute();
	}

	return false;
}

Context * If::getBeginContext() {
	return getFirst();
}

Context * If::getEndContext() {
	return getLast();
}

}  // namespace icL::context::code::control
