#include "resources.h"

#include "resource.h"

#include <QStringBuilder>

namespace icL::toolkit::session {

Resources::Resources(Item * parent)
	: Folder(parent) {}

bool Resources::setResourceList(
  const QString & path, const QVariantList & files) {
	clear();

	bool ret = true;

	for (const auto & strVar : files) {
		auto res = new Resource(this);

		ret = ret && res->setPath(path % "/res/" % strVar.toString());
		children.append(res);

		if (!ret)
			break;
	}

	return ret;
}

QVariant Resources::data(int column) {
	if (column == 0) {
		return {QObject::tr("Resources")};
	}
	else {
		return {};
	}
}

QString Resources::getIcon() {
	return "resources.svg";
}

}  // namespace icL::toolkit::session
