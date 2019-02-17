#ifndef icL_editor_Plugin
#define icL_editor_Plugin

#include <QObject>
#include <QQmlExtensionPlugin>



/**
 * @brief Export editor C++ classes to QML.
 */
class EditorPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    explicit EditorPlugin(QObject * parent = nullptr);

signals:

public slots:

    // QQmlTypesExtensionInterface interface
public:
    void registerTypes(const char * uri) override;
};

#endif  // icL_editor_Plugin
