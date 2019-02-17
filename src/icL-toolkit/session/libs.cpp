#include "libs.h"

#include "../utils/remotecall.h"
#include "lib.h"

#include <QStringBuilder>
#include <QVariant>

namespace icL::toolkit::session {

Libs::Libs(Item * parent)
    : Folder(parent) {}

bool Libs::setLibsList(const QString & path, const QVariantList & libs) {
    clear();

    bool ret = true;

    for (const auto & strVar : libs) {
        auto res = new Lib(this);

        ret = ret && res->setPath(path % "/lib/" % strVar.toString());
        children.append(res);

        if (!ret)
            break;
    }

    return ret;
}

QVariant Libs::data(int column) {
    if (column == 0) {
        return {QObject::tr("Libs")};
    }

    return {};
}

QString Libs::getIcon() {
    return "libs.svg";
}

enum Actions { NewLib = 0 };

const utils::Actions & Libs::getActionsList() {
    static utils::Actions actions = {new utils::RemoteCall(
      Actions::NewLib, QObject::tr("New library"),
      {new utils::RemoteArg(QObject::tr("Library name"))})};

    return actions;
}

bool Libs::runAction(utils::RemoteCall * call) {
    return false;
}

}  // namespace icL::toolkit::session
