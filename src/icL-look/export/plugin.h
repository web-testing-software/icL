#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <QQmlExtensionPlugin>

namespace icL::look {

class Plugin : public QQmlExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
	explicit Plugin(QObject * parent = nullptr);

signals:

public slots:

	// QQmlTypesExtensionInterface interface
public:
	void registerTypes(const char *uri) override;
};

}  // namespace icL::look

#endif  // PLUGIN_H
