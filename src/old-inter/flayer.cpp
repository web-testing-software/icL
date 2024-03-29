#include "flayer.h"

namespace old::inter {


Flayer::Flayer(memory::InterLevel * il)
    : memory::Node(il) {

	source = nullptr;
}


QChar Flayer::flyNextChar() {
	if (source == nullptr) {
		source = il->vm->source();
	}

	QChar ch = position >= end ? '\0' : source->at(position);

	while ((ch == ' ' || ch == '\n' || ch == '\t') && position < end - 1) {
		ch = source->at(++position);

		if (ch == '`') {
			if (!flyComment()) {
				return '\0';
			}
			ch = ' ';
		}
	}

	if (position >= source->length()) {
		return '\0';
	}
	else if (position == end) {
		return ' ';
	}

	return ch;
}

QString Flayer::flyKeyword() {
	start = position;

	QChar ch;

	do {
		ch = source->at(position);
	} while ((ch.isLetter() || ch.isDigit()) && ++position < end);

	return source->mid(start, position - start);
}

QString Flayer::flyVarName() {
	++position;

	return flyKeyword();
}

std::tuple<int, double, bool> Flayer::flyNumber() {
	int    ret_int;
	double ret_double;
	bool   is_int;
	bool   point_catched  = false;
	int    point_position = position;
	QChar  ch             = source->at(position);

	start = position;

	if (ch == '-') {
		ch = source->at(++position);
	}

	while ((ch.isDigit() || (!point_catched && ch == '.')) &&
	       position < end - 1) {
		if (ch == '.') {
			point_position = position;
			point_catched  = true;
		}

		ch = source->at(++position);
	}

	// interpret 1.prop as 1 .prop, not 1. prop -> int
	// 1.1.prop as 1.1 .prop, not 1.1. prop -> double
	if (source->at(position - 1) == '.') {
		--position;

		if (point_position == position - 1) {
			point_catched = false;
		}
	}

	QString str = source->mid(start, position - start);
	bool    ok;

	if (point_catched) {
		ret_double = str.toDouble(&ok);
		is_int     = false;
	}
	else {
		ret_int = str.toDouble(&ok);
		is_int  = true;
	}

	if (!ok) {
		il->vm->exception(
		  {-500, QStringLiteral("%1 is not a number.").arg(str)});

		highlightError();
	}

	return {ret_int, ret_double, is_int};
}

std::pair<context::Prefix, QString> Flayer::flyProperty() {
	start = ++position;

	bool            prefix_catched = false;
	QChar           ch             = source->at(position);
	context::Prefix ret_prefix     = context::Prefix::None;
	QString         name;

	do {
		ch = source->at(position);

		if (ch == '-') {
			QString prefix = source->mid(start, position - start - 1);

			prefix_catched = true;

			if (prefix == "attr") {
				ret_prefix = context::Prefix::Attr;
			}
			else if (prefix == "data") {
				ret_prefix = context::Prefix::Data;
			}
			else if (prefix == "css") {
				ret_prefix = context::Prefix::Css;
			}
			else if (!prefix.isEmpty()) {
				prefix_catched = false;
			}

			if (!prefix_catched) {
				highlightError();
				break;
			}
			else {
				start = position + 1;
			}
		}
	} while ((ch.isLetter() || (ch == '-' && !prefix_catched)) &&
	         ++position < end);

	name = source->mid(start, position - start);

	if (name.isEmpty()) {
		il->vm->exception({-501, "Property name is empty"});

		highlightError();
	}

	return {ret_prefix, name};
}

void Flayer::stepForward() {
	++position;
}

void Flayer::stepBack() {
	--position;
}

std::pair<memory::CodeFragment, bool> Flayer::flyLogicFrag() {
	bool                 is_logic = false;
	memory::CodeFragment out;
	QChar                ch = flyNextChar();

	if (ch == 'L') {
		is_logic = true;
		position++;
	}

	out.begin = position + 1;

	findBracketPair();
	out.end    = position - 1;
	out.source = source;

	return {out, is_logic};
}

memory::CodeFragment Flayer::flyAnyExistsFrag() {
	memory::CodeFragment out;

	out.begin = ++position + 1;
	findBracketPair();

	out.end    = position - 1;
	out.source = source;

	return out;
}

memory::CodeFragment Flayer::flyCode() {
	memory::CodeFragment out;

	out.begin = position + 1;
	findBracketPair();

	out.end    = position - 1;
	out.source = source;

	return out;
}

QString Flayer::flyString() {
	int   begin = ++position;
	QChar ch    = source->at(position);

	while (ch != '"' && position < end - 1) {
		if (ch == '\\') {
			++position;
		}
		ch = source->at(++position);
	}

	if (position == end - 1 && ch != '"') {
		il->vm->exception({-300, "No closing \" found."});

		highlightError();
	}

	++position;

	return source->mid(begin, position - begin - 1);
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

void Flayer::highlightError() {
	il->vms->setSColor(memory::SelectionColor::Error);
	il->vms->highlight(start, position);
}


bool Flayer::flyComment() {
	start = position;

	QChar ch;
	QChar ch_next = source->at(position < end - 2 ? position + 1 : position);
	QChar ch_next_next =
	  source->at(position < end - 3 ? position + 2 : position);

	if (ch_next != '`') {
		while (position < end - 2 && ch != '`') {
			ch = source->at(++position);

			if (ch == '\n') {
				il->vm->exception({-306, "Unexpected token \n, expected `"});

				highlightError();

				return false;
			}
		}

		if (position == end - 1 && ch != '`') {
			il->vm->exception(
			  {-306,
			   QStringLiteral("Unexpected token %1, expected `")
			     .arg(position == source->length() ? "EOF" : QString(ch))});

			highlightError();

			return false;
		}
	}
	else if (ch_next_next != '`') {
		while (position < end - 2 && ch != '\n') {
			ch = source->at(++position);
		}

		if (position == end - 1 && ch != '\n') {
			il->vm->exception({-306, "Unexpected token EOF, expected \n"});

			highlightError();

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

			highlightError();

			return false;
		}
	}

	return true;
}

void Flayer::findBracketPair() {
	QChar   ch = source->at(position);
	QString brackets;

	brackets.reserve(128);
	start = position - 1;


	if (ch != '(' && ch != '[' && ch != '{') {
		il->vm->exception(
		  {-300, QStringLiteral("Token %1 is not a open bracket").arg(ch)});

		highlightError();
	}

	do {
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
				break;

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

		++position;
	} while (position < end);

	++position;

	if (position == end && !brackets.isEmpty()) {
		il->vm->exception(
		  {-300, QStringLiteral("No pair for %1").arg(brackets.front())});

		highlightError();
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

	highlightError();
	brackets.clear();
}

}  // namespace old::inter
