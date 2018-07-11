#include "webelement.h"

#include <QStringBuilder>

namespace icL::memory {

QString IclElement::variable() {
	return m_variable;
}

QString IclElement::nthVariable(int n) {
	return m_variable % '[' % QString::number(n) % ']';
}

int IclElement::count() {
	return m_count;
}


QString W3cElement::variable() {
	return variables[0];
}

QString W3cElement::nthVariable(int n) {
	return variables[n];
}

int W3cElement::count() {
	return variables.length();
}

QString W3cElement::indentifier =
  "element-6066-11e4-a52e-4f735466cecf";

}  // namespace icL::memory
