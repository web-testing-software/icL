#ifndef icL_look_Effect
#define icL_look_Effect

#include "baselook.h"

#include <QColor>



namespace icL::look {

/**
 * @brief The Effect class decribes a look for an effect
 */
class Effect : public BaseLook
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(QColor normal READ normal WRITE setNormal NOTIFY normalChanged)
    Q_PROPERTY(QColor  hover READ hover  WRITE setHover  NOTIFY hoverChanged)
    Q_PROPERTY(QColor active READ active WRITE setActive NOTIFY activeChanged)
    // clang-format on

public:
    /**
     * @brief Effect is the default constructor
     * @param parent is the default QObject arg
     */
    explicit Effect(QObject * parent = nullptr);

    /**
     * @brief normal is the default effect color
     * @return the default effect color
     */
    QColor normal() const;

    /**
     * @brief hover is the effect color for hover state
     * @return the effect color for hover state
     */
    QColor hover() const;

    /**
     * @brief active is the effect color for active state
     * @return the effect color for active state
     */
    QColor active() const;

    void setUp(const QJsonObject & obj) override;

    QJsonObject getUp() override;

signals:
    void normalChanged(QColor normal);
    void hoverChanged(QColor hover);
    void activeChanged(QColor active);

public slots:
    /**
     * @brief setNormal changes the default effect color
     * @param normal is the new default effect color
     */
    void setNormal(const QColor & normal);

    /**
     * @brief setHover changes the effect color for hover state
     * @param hover is the new effect color for hover state
     */
    void setHover(const QColor & hover);

    /**
     * @brief setActive changes the effect color for active state
     * @param active is the new effect color for active state
     */
    void setActive(const QColor & active);

private:
    QColor m_normal;
    QColor m_hover;
    QColor m_active;
};

}  // namespace icL::look

#endif  // icL_look_Effect
