#include "../../parser.h"
#include "driver.h"

const QStringList keywoords = {
	//
};

vm::main::Driver::Driver (QObject *parent)
	: QObject (parent) {

}

vm::main::Server * vm::main::Driver::server () {
	return &m_server;
}

void vm::main::Driver::openFile (const QString &path) {

}

int vm::main::Driver::currentCommand () {
	return m_currentCommand;
}

const QVariantMap * vm::main::Driver::currentParams () {
	return &m_currentParams;
}

void vm::main::Driver::setCurrentCommand (int n_currentCommand) {
	m_currentCommand = n_currentCommand;
}

void vm::main::Driver::setCurrentParams (const QVariantMap &n_currentParams) {
	m_currentParams.clear ();
	m_currentParams = n_currentParams;
}

vm::memory::DataContainer * vm::main::Driver::dataContainer () {
	return &m_dataContainer;
}
