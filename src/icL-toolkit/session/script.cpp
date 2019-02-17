#include "script.h"

#include "../utils/remotecall.h"

#include <QFile>
#include <QVariant>

namespace icL::toolkit::session {

Script::Script(Item * parent)
    : Finaly(parent) {}

bool Script::setPath(const QString & path) {
    return checkIfFileExist(path, name);
}

int Script::columnCount() {
    return 1;
}

QVariant Script::data(int /*column*/) {
    return {name};
}

int Script::selfIndex() {
    return 0;
}

QString Script::getIcon() {
    return "icL-file.svg";
}

enum Actions { Rename = 0, MakeLib = 1 };

const utils::Actions & Script::getActionsList() {
    static utils::Actions actions = {
      new utils::RemoteCall(
        Actions::Rename, QObject::tr("Rename"),
        {new utils::RemoteArg(QObject::tr("New name"))}),
      new utils::RemoteCall(
        Actions::MakeLib, QObject::tr("Make library from script"), {})};

    return actions;
}

bool Script::runAction(utils::RemoteCall * call) {
    return false;
}

}  // namespace icL::toolkit::session
