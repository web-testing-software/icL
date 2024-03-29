#ifndef icL_look_Side
#define icL_look_Side

#include "listitem.h"

#include <QColor>



namespace icL::look {

class LinkAdv;
class Input;

/**
 * @brief The Side class describes a look for a start page side
 */
class Side : public ListItem
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY backgroundChanged)
    Q_PROPERTY(icL::look::TextLook* header READ header NOTIFY headerChanged)
    Q_PROPERTY(icL::look::Input*     input READ input  NOTIFY inputChanged)
    Q_PROPERTY(icL::look::LinkAdv*  button READ button NOTIFY buttonChanged)
    // clang-format on

public:
    /**
     * @brief Side is the default contructor
     * @param parent is the default QObject arg
     */
    explicit Side(QObject * parent = nullptr);

    ~Side();

    /**
     * @brief header is a look for a side header
     * @return the look for a side header
     */
    TextLook * header() const;

    /**
     * @brief background is the brackground color
     * @return the color of background
     */
    QColor background() const;

    /**
     * @brief input is the look of text input
     * @return the look for text input
     */
    Input * input() const;

    /**
     * @brief button is the look of buttons
     * @return the look for buttons
     */
    LinkAdv * button() const;

    void setUp(const QJsonObject & obj) override;

    QJsonObject getUp() override;

signals:
    void backgroundChanged(QColor background);
    void headerChanged(TextLook * header);
    void inputChanged(Input * input);
    void buttonChanged(LinkAdv * button);

public slots:
    /**
     * @brief setBackground changes the background color
     * @param background is the new background color
     */
    void setBackground(const QColor & background);

private:
    TextLook * m_header = nullptr;
    QColor     m_background;
    Input *    m_input  = nullptr;
    LinkAdv *  m_button = nullptr;
};

}  // namespace icL::look

#endif  // icL_look_Side
