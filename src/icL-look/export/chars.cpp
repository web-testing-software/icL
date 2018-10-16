#include "chars.h"

namespace icL::look {

Chars::Chars(QObject * parent)
	: QObject(parent) {
	if (instance == nullptr) {
		instance = this;
	}
}

CharFormat Chars::comment  = {};
CharFormat Chars::function = {};
CharFormat Chars::global   = {};
CharFormat Chars::keyword  = {};
CharFormat Chars::local    = {};
CharFormat Chars::method   = {};
CharFormat Chars::number   = {};
CharFormat Chars::property = {};
CharFormat Chars::string   = {};
CharFormat Chars::system   = {};
CharFormat Chars::type     = {};

HighlightChars Chars::occurence = {};

CharFormat Chars::error   = {};
CharFormat Chars::warning = {};

void Chars::update() {
	if (instance != nullptr) {
		emit instance->highlight();
	}
}

Chars * Chars::instance = nullptr;

}  // namespace icL::look
