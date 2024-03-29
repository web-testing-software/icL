#ifndef icL_look_Highlight
#define icL_look_Highlight

#include "../base/baselook.h"

#include <QColor>



namespace icL::look {

/**
 * @brief The Highlight class describes a look for highlighting fragment of text
 */
class Highlight : public BaseLook
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY backgroundChanged)
    Q_PROPERTY(QColor     border READ border     WRITE setBorder     NOTIFY borderChanged)
    // clang-format on

public:
    /**
     * @brief Highlight is the default constructor
     * @param parent is the default QObject arg
     */
    explicit Highlight(QObject * parent = nullptr);

    /**
     * @brief background is the color of background
     * @return the color for background
     */
    QColor background() const;

    /**
     * @brief border is the color of border
     * @return the color for border
     */
    QColor border() const;

    void setUp(const QJsonObject & obj) override;

    QJsonObject getUp() override;

signals:
    void backgroundChanged(QColor background);
    void borderChanged(QColor border);

public slots:
    /**
     * @brief setBackground changes the color of background
     * @param background is the new color for background
     */
    void setBackground(const QColor & background);
    /**
     * @brief setBorder changes the color of border
     * @param border is the new color for border
     */
    void setBorder(const QColor & border);

private:
    QColor m_background;
    QColor m_border;
};

}  // namespace icL::look

#endif  // icL_look_Highlight
