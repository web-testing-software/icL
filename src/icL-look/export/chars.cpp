#include "chars.h"

namespace icL::look {

Chars::Chars(QObject * parent)
	: QObject(parent) {
	if (instance == nullptr) {
		instance = this;
	}
}

TextCharFormat Chars::comment   = {};
TextCharFormat Chars::function  = {};
TextCharFormat Chars::global    = {};
TextCharFormat Chars::keyword   = {};
TextCharFormat Chars::local     = {};
TextCharFormat Chars::method    = {};
TextCharFormat Chars::number    = {};
TextCharFormat Chars::property  = {};
TextCharFormat Chars::string    = {};
TextCharFormat Chars::system    = {};
TextCharFormat Chars::type      = {};
HighlightChars Chars::occurence = {};
TextCharFormat Chars::error     = {};
TextCharFormat Chars::warning   = {};

void Chars::update() {
	if (instance != nullptr) {
		emit instance->highlight();
	}
}

Chars * Chars::instance = nullptr;

}  // namespace icL::look
