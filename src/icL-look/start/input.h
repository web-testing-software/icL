#ifndef icL_look_Input
#define icL_look_Input

#include "../base/link.h"

#include <QColor>



namespace icL::look {

/**
 * @brief The Input class describes a text input look
 */
class Input : public Link
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(icL::look::TextLook *  inactive READ inactive  NOTIFY inactiveChanged)
    Q_PROPERTY(icL::look::TextLook * selection READ selection NOTIFY selectionChanged)
    Q_PROPERTY(QColor cursor READ cursor WRITE setCursor NOTIFY cursorChanged)
    // clang-format on

public:
    /**
     * @brief Input is the default contructor
     * @param parent is the default QObject arg
     */
    explicit Input(QObject * parent = nullptr);
    ~Input();

    /**
     * @brief inactive is the look for an inactive input
     * @return the look for an inactive input
     */
    TextLook * inactive() const;

    /**
     * @brief selection is the look for an selection
     * @return the for an selection
     */
    TextLook * selection() const;

    /**
     * @brief cursor is the color for the text cursor
     * @return the color for the text input
     */
    QColor cursor() const;

    void setUp(const QJsonObject & obj) override;

    QJsonObject getUp() override;

signals:
    void cursorChanged(QColor cursor);
    void inactiveChanged(TextLook * inactive);
    void selectionChanged(TextLook * selection);

public slots:
    /**
     * @brief setCursor changes the color of text cursor
     * @param cursor is the new color for text cursors
     */
    void setCursor(const QColor & cursor);

private:
    TextLook * m_inactive  = nullptr;
    TextLook * m_selection = nullptr;
    QColor     m_cursor;
};

}  // namespace icL::look

#endif  // icL_look_Input
