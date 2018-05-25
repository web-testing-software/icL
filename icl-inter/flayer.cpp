#include "flayer.h"

namespace icL::inter::_private {


Flayer::Flayer(memory::InterLevel * il, const QString * source)
	: memory::Node(il)
	, source(source) {}


QChar Flayer::getNextChar() {
	QChar ch = source->at(position);

	while (ch == ' ' || ch == '\n' || ch == '\t' || position < end) {
		ch = source->at(++position);

		if (ch == '`') {
			if (!flyComment()) {
				return '\0';
			}
		}
	}

	if (position == source->length()) {
		return '\0';
	}
	else if (position == end) {
		return ' ';
	}

	return ch;
}

QString Flayer::getKeyword() {
	int   start = position;
	QChar ch    = source->at(position);

	while (ch.isLetter()) {
		ch = source->at(++position);
	}

	return source->mid(start, position);
}

QString Flayer::getVarName() {
	++position;

	return getKeyword();
}

void Flayer::stepBack() {
	--position;
}

std::pair<memory::CodeFragment, bool> Flayer::getLogicFrag() {
	bool                 is_logic = false;
	memory::CodeFragment out;
	QChar                ch = getNextChar();

	out.begin = position;

	if (ch == 'L') {
		is_logic = true;
		position++;
	}

	findBracketPair();
	out.end    = position;
	out.source = source;

	return {out, is_logic};
}

int Flayer::getPosition() const {
	return position;
}

void Flayer::setPosition(int value) {
	position = value;
}

void Flayer::setEnd(int value) {
	end = value;
}

bool Flayer::flyComment() {
	QChar ch;
	QChar ch_next = source->at(position < end - 2 ? position + 1 : position);
	QChar ch_next_next =
	  source->at(position < end - 3 ? position + 2 : position);

	if (ch_next != '`') {
		while (position < end - 2 && ch != '`') {
			ch = source->at(++position);

			if (ch == '\n') {
				il->vm->exception({-306, "Unexpected token \n, expected `"});
				return false;
			}
		}

		if (position == end - 1 && ch != '`') {
			il->vm->exception(
			  {-306,
			   QStringLiteral("Unexpected token %1, expected `")
				 .arg(position == source->length() ? "EOF" : QString(ch))});
			return false;
		}
	}
	else if (ch_next_next != '`') {
		while (position < end - 2 && ch != '\n') {
			ch = source->at(++position);
		}

		if (position == end - 1 && ch != '\n') {
			il->vm->exception({-306, "Unexpected token EOF, expected \n"});
			return false;
		}
	}
	else {
		position += 2;

		while (position < end - 4 &&
			   !(ch == '`' && ch_next == '`' && ch_next_next == '`')) {
			ch = source->at(++position);

			if (ch == '`') {
				ch_next      = source->at(position + 1);
				ch_next_next = source->at(position + 2);
			}
		}

		if (
		  position == end - 3 &&
		  !(ch == '`' && ch_next == '`' && ch_next_next == '`')) {
			il->vm->exception(
			  {-306,
			   QStringLiteral("Unexpected token %1, expected ```")
				 .arg(
				   end == source->length() ? "EOF" : source->mid(end - 1, 1))});
			return false;
		}
	}

	return true;
}

void Flayer::findBracketPair() {
	QChar   ch = source->at(position);
	QString brackets;

	brackets.reserve(128);

	if (ch != '(' && ch != '[' && ch != '{') {
		il->vm->exception(
		  {-300, QStringLiteral("Token %1 is not a open bracket").arg(ch)});
	}

	while (position < end) {
		ch = source->at(position);

		if (brackets.endsWith('"')) {
			if (ch == '\\') {
				++position;
			}
			else if (ch == '"') {
				brackets.chop(1);
			}
		}
		else {
			switch (ch.toLatin1()) {

			case '(':
			case '[':
			case '{':
			case '"':
				brackets.append(ch);
				break;

			case ')':
				if (brackets.endsWith('(')) {
					brackets.chop(1);
				}
				else {
					sendWrongBrackerPair(brackets, ch);
				}
				break;

			case ']':
				if (brackets.endsWith('[')) {
					brackets.chop(1);
				}
				else {
					sendWrongBrackerPair(brackets, ch);
				}
			case '}':
				if (brackets.endsWith('{')) {
					brackets.chop(1);
				}
				else {
					sendWrongBrackerPair(brackets, ch);
				}
				break;
			}
		}

		if (brackets.isEmpty()) {
			break;
		}
	}

	if (position == end && !brackets.isEmpty()) {
		il->vm->exception(
		  {-300, QStringLiteral("No pair for %1").arg(brackets.front())});
	}
}

void Flayer::sendWrongBrackerPair(QString & brackets, const QChar & ch) {
	QChar ch_local;

	if (brackets.isEmpty()) {
		il->vm->exception({-300, QStringLiteral("No pair for %1").arg(ch)});
	}
	else {
		ch_local = brackets.back();

		if (ch_local != '(' && ch_local != '[' && ch_local != '{') {
			il->vm->exception({-300, QStringLiteral("No pair for %1").arg(ch)});
		}
		else {
			il->vm->exception({-300, QStringLiteral("Wrong bracket pair %1 %2")
									   .arg(brackets.right(1), QString(ch))});
		}
	}

	brackets.clear();
}

}  // namespace icL::inter::_private
