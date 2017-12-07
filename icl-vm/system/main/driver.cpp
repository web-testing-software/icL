#include "../../parser.h"
#include "driver.h"



namespace vm::main {

Driver::Driver (QObject *parent)
	: QObject (parent) {

}

Server * Driver::server () {
	return &m_server;
}

void Driver::openFile (const QString &path) {

}

int Driver::currentCommand () {
	return m_currentCommand;
}

const QVariantMap * Driver::currentParams () {
	return &m_currentParams;
}

void Driver::setCurrentCommand (int n_currentCommand) {
	m_currentCommand = n_currentCommand;
}

void Driver::setCurrentParams (const QVariantMap &n_currentParams) {
	m_currentParams.clear ();
	m_currentParams = n_currentParams;
}

vm::memory::DataContainer * Driver::dataContainer () {
	return &m_dataContainer;
}

}
