#ifndef icL_look_Link
#define icL_look_Link

#include "baselook.h"

#include <QObject>



namespace icL::look {

class TextLook;

/**
 * @brief The Link class describes a look for links
 */
class Link : public BaseLook
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(icL::look::TextLook * normal READ normal NOTIFY normalChanged)
    Q_PROPERTY(icL::look::TextLook *  hover READ hover  NOTIFY hoverChganged)
    Q_PROPERTY(icL::look::TextLook * active READ active NOTIFY activeChanged)
    // clang-format on

public:
    /**
     * @brief Link is the default constructor
     * @param parent is the default QObject arg
     */
    explicit Link(QObject * parent = nullptr);

    ~Link();

    /**
     * @brief normal is the default text color
     * @return the default text color
     */
    TextLook * normal() const;

    /**
     * @brief hover is the hovered text color
     * @return the hovered text color
     */
    TextLook * hover() const;

    /**
     * @brief active is the active link color
     * @return the active link color
     */
    TextLook * active() const;

    void setUp(const QJsonObject & obj) override;

    QJsonObject getUp() override;

signals:
    void normalChanged(TextLook * normal);
    void hoverChganged(TextLook * hover);
    void activeChanged(TextLook * active);

private:
    TextLook * m_normal = nullptr;
    TextLook * m_hover  = nullptr;
    TextLook * m_active = nullptr;
};

}  // namespace icL::look

#endif  // icL_look_Link
