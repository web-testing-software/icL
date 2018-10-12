#include "libs.h"

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
	else {
		return {};
	}
}

QString Libs::getIcon() {
	return "libs.svg";
}

}  // namespace icL::toolkit::session
