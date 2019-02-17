#ifndef icL_look_EffectAdv
#define icL_look_EffectAdv

#include "effect.h"

namespace icL::look {

/**
 * @brief The EffectAdv class
 */
class EffectAdv : public Effect
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(QColor activeHover READ activeHover WRITE setActiveHover NOTIFY activeHoverChanged)
    // clang-format on

public:
    /**
     * @brief EffectAdv is the default constructor
     * @param parent is the default QObject arg
     */
    explicit EffectAdv(QObject * parent = nullptr);

    /**
     * @brief activeHover is the color for link in active and hover state
     * @return the color for link in active and hover state
     */
    QColor activeHover() const;

    void setUp(const QJsonObject & obj) override;

    QJsonObject getUp() override;

signals:
    void activeHoverChanged(QColor activeHover);

public slots:
    /**
     * @brief setActiveHover changes the link color for active and hover state
     * @param activeHover is the new link color for active and hover state
     */
    void setActiveHover(const QColor & activeHover);

private:
    QColor m_activeHover;
};

}  // namespace icL::look

#endif  // icL_look_EffectAdv
