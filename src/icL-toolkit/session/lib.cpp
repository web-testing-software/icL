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

enum Actions { Rename = 0, Delete = 1 };

const utils::Actions & Lib::getActionsList() {
	static utils::Actions actions = {
	  new utils::RemoteCall(
		Actions::Rename, QObject::tr("Rename"),
		{new utils::RemoteArg(QObject::tr("New name"))}),
	  new utils::RemoteCall(Actions::Delete, QObject::tr("Delete"), {})};

	return actions;
}

bool Lib::runAction(utils::RemoteCall * call) {
	if (call->id() != Actions::Rename) {
		return false;
	}

	// TODO: Write rename code here
	return true;
}

}  // namespace icL::toolkit::session
