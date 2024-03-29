#ifndef icL_toolkit_Plugin
#define icL_toolkit_Plugin

#include <QQmlExtensionPlugin>

/**
 * @brief The ToolkitPlugin class export the C++ toolkit classes to QML
 */
class ToolkitPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    explicit ToolkitPlugin(QObject * parent = nullptr);

signals:

public slots:

    // QQmlTypesExtensionInterface interface
public:
    void registerTypes(const char * uri) override;
};

#endif  // icL_toolkit_Plugin
