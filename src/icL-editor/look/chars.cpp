#include "chars.h"

namespace icL::editor::look {

Chars::Chars(QObject * parent)
	: QObject(parent) {
	if (instance == nullptr) {
		instance = this;
	}
}

QTextCharFormat Chars::comment   = {};
QTextCharFormat Chars::function  = {};
QTextCharFormat Chars::global    = {};
QTextCharFormat Chars::keyword   = {};
QTextCharFormat Chars::local     = {};
QTextCharFormat Chars::method    = {};
QTextCharFormat Chars::number    = {};
QTextCharFormat Chars::property  = {};
QTextCharFormat Chars::string    = {};
QTextCharFormat Chars::system    = {};
QTextCharFormat Chars::type      = {};
Highlight       Chars::occurence = {};
QColor          Chars::error     = {};
QColor          Chars::warning   = {};

void Chars::update() {
	if (instance != nullptr) {
		emit instance->highlight();
	}
}

Chars * Chars::instance = nullptr;

}  // namespace icL::editor::look
