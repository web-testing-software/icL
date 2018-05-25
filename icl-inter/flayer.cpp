#include "flayer.h"

namespace icL::inter::_private {


Flayer::Flayer(const QString * source)
	: source(source) {}


QChar Flayer::getNextChar() {
	QChar ch = source->at(position);

	while (ch == ' ' || ch == '\n' || ch == '\t' || position < end) {
		position++;
		ch = source->at(position);

		if (ch == '`') {
			flyComment();
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

int Flayer::getPosition() const {
	return position;
}

void Flayer::setPosition(int value) {
	position = value;
}

void Flayer::setEnd(int value) {
	end = value;
}

}  // namespace icL::inter::_private
