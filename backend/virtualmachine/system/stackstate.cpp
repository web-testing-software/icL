#include "stackstate.h"


vm::system::StackState::StackState (int stackLevel) {

}

void vm::system::StackState::setWebElement (const QString &name, WebElement webElement) {

}

WebElement vm::system::StackState::getWebElement (const QString &name) {

}

bool vm::system::StackState::isWebElement (const QString &name) {

}

vm::system::StackState * vm::system::StackState::getPrev () {

}

bool vm::system::StackState::isLast () {

}

QVariant vm::system::StackState::getStackValue () {

}

int vm::system::StackState::getSearchedCommand () {

}

LogicBlock * vm::system::StackState::getLogicBlock () {

}

int vm::system::StackState::getStackLevel () {

}

int vm::system::StackState::getMaxStackLevel () {

}

vm::system::StackStateIterator::StackStateIterator () {

}

vm::system::StackState * vm::system::StackStateIterator::stack () {

}

void vm::system::StackStateIterator::openNewStack () {

}

void vm::system::StackStateIterator::closeStack () {

}

bool vm::system::StackStateIterator::checkType (const QString &name, vm::system::DataState::Type &type) {

}

bool vm::system::StackStateIterator::isWebElement (const QString &name) {

}

WebElement vm::system::StackStateIterator::getWebElement (const QString &name) {

}

QVariant vm::system::StackStateIterator::getValue (const QString &name) {

}
