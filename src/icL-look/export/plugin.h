#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <QQmlExtensionPlugin>

class LookPlugin : public QQmlExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
	explicit LookPlugin(QObject * parent = nullptr);

signals:

public slots:

	// QQmlTypesExtensionInterface interface
public:
	void registerTypes(const char *uri) override;
};

#endif  // PLUGIN_H
