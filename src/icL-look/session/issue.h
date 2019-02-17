#ifndef icL_look_Issue
#define icL_look_Issue

#include "../base/linkadv.h"



namespace icL::look {

class Effect;

/**
 * @brief The Issue class describe a look for a issue item
 */
class Issue : public LinkAdv
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(icL::look::Effect* effect READ effect NOTIFY effectChanged)
    // clang-format on

public:
    /**
     * @brief Issue is the default constructor
     * @param parent is the default QObject arg
     */
    explicit Issue(QObject * parent = nullptr);

    ~Issue();

    /**
     * @brief effect is the underline effect
     * @return the underline effect
     */
    Effect * effect() const;

    void setUp(const QJsonObject & obj) override;

    QJsonObject getUp() override;

signals:
    void effectChanged(Effect * effect);

private:
    Effect * m_effect;
};

}  // namespace icL::look

#endif  // icL_look_Issue
