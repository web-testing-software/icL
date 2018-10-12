#include "lib.h"

#include "../utils/remotecall.h"

#include <QFile>
#include <QStringBuilder>
#include <QVariant>

namespace icL::toolkit::session {

Lib::Lib(Item * parent)
	: Finaly(parent) {}

bool Lib::setPath(const QString & path) {
	return checkIfFileExist(path, libname);
}

int Lib::columnCount() {
	return 1;
}

QVariant Lib::data(int column) {
	if (column == 0) {
		return {libname};
	}
	else {
		return {};
	}
}

int Lib::selfIndex() {
	return 1;
}

QString Lib::getIcon() {
	return "lib.svg";
}

const utils::Actions & Lib::getActionsList() {
	static utils::Actions actions = {new utils::RemoteCall(
	  0, QObject::tr("Rename"),
	  {new utils::RemoteArg(QObject::tr("New name"))})};

	return actions;
}

bool Lib::runAction(utils::RemoteCall * call) {
	if (call->id() != 0) {
		return false;
	}

	// TODO: Write rename code here
	return true;
}

}  // namespace icL::toolkit::session
