#ifndef icL_look_Static
#define icL_look_Static

#include "../base/baselook.h"

#include <QColor>



namespace icL::look {

class LinkAdv;
class EffectAdv;

/**
 * @brief The Static class describes a look for the static left bar
 */
class Static : public BaseLook
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(icL::look::LinkAdv*        menuItem READ menuItem      NOTIFY menuItemChanged)
    Q_PROPERTY(icL::look::LinkAdv*     submenuItem READ submenuItem   NOTIFY submenuItemChanged)
    Q_PROPERTY(icL::look::EffectAdv* submenuBorder READ submenuBorder NOTIFY submenuBorderChanged)
    Q_PROPERTY(icL::look::LinkAdv*          button READ button        NOTIFY buttonChanged)
    Q_PROPERTY(QColor    background READ background    WRITE setBackground    NOTIFY backgroundChanged)
    Q_PROPERTY(QColor        handle READ handle        WRITE setHandle        NOTIFY handleChanged)
    Q_PROPERTY(QColor handleVisible READ handleVisible WRITE setHandleVisible NOTIFY handleVisibleChanged)
    Q_PROPERTY(QColor  handleHidden READ handleHidden  WRITE setHandleHidden  NOTIFY handleHiddenChanged)
    Q_PROPERTY(QColor    menuShadow READ menuShadow    WRITE setMenuShadow    NOTIFY menuShadowChanged)
    Q_PROPERTY(QColor submenuShadow READ submenuShadow WRITE setSubmenuShadow NOTIFY submenuShadowChanged)
    // clang-format on

public:
    /**
     * @brief Static is the default constructor
     * @param parent is the default QObject arg
     */
    explicit Static(QObject * parent = nullptr);

    /**
     * @brief menuItem is the look of horizontal menu items
     * @return the look for horizontal menu items
     */
    LinkAdv * menuItem() const;

    /**
     * @brief submenuItem is the look for dropdown menu items
     * @return the look for dropdown menu items
     */
    LinkAdv * submenuItem() const;

    /**
     * @brief submenuBorder is the color of left border of item
     * @return the color for the left border of item
     */
    EffectAdv * submenuBorder() const;

    /**
     * @brief button it the look of static panel buttons
     * @return the look for static panel buttons
     */
    LinkAdv * button() const;

    /**
     * @brief background is the color of backgound
     * @return the color for backgound
     */
    QColor background() const;

    /**
     * @brief handle is the color of view central handle
     * @return the color for central handler
     */
    QColor handle() const;

    /**
     * @brief handleVisible is the color of a active handler
     * @return the colr for an active handler
     */
    QColor handleVisible() const;

    /**
     * @brief handleHidden is the color of an inactive handler
     * @return the color for an inactive handler
     */
    QColor handleHidden() const;

    /**
     * @brief menuShadow is the color of main menu shadow
     * @return the color for main menu shadow
     */
    QColor menuShadow() const;

    /**
     * @brief submenuShadow is the color of submenu shadow
     * @return th ecolor for submenu shadow
     */
    QColor submenuShadow() const;

    // BaseLook interface
    void        setUp(const QJsonObject & obj) override;
    QJsonObject getUp() override;

signals:
    void menuItemChanged(LinkAdv * menuItem);
    void submenuItemChanged(LinkAdv * submenuItem);
    void submenuBorderChanged(EffectAdv * submenuBorder);
    void buttonChanged(LinkAdv * button);
    void backgroundChanged(QColor background);
    void handleChanged(QColor handle);
    void handleVisibleChanged(QColor handleVisible);
    void handleHiddenChanged(QColor handleHidden);
    void menuShadowChanged(QColor menuShadow);
    void submenuShadowChanged(QColor submenuShadow);

public slots:
    /**
     * @brief setBackground changes the color of background
     * @param background is the new color for background
     */
    void setBackground(const QColor & background);

    /**
     * @brief setHandle changes the color of central handler
     * @param handle is the new color for central handler
     */
    void setHandle(const QColor & handle);

    /**
     * @brief setHandleVisible changes the color of an active handler
     * @param handleVisible is the color for an active handler
     */
    void setHandleVisible(const QColor & handleVisible);

    /**
     * @brief setHandleHidden changes the color of an inactive handler
     * @param handleHidden is the color for inactive handler
     */
    void setHandleHidden(const QColor & handleHidden);

    /**
     * @brief setMenuShadow changes the color of main menu shadow
     * @param menuShadow is the color for main menu shadow
     */
    void setMenuShadow(const QColor & menuShadow);

    /**
     * @brief setSubmenuShadow changes the color of submenu shadow
     * @param submenuShadow is the new color for submenu shadow
     */
    void setSubmenuShadow(const QColor & submenuShadow);

private:
    LinkAdv *   m_menuItem      = nullptr;
    LinkAdv *   m_submenuItem   = nullptr;
    EffectAdv * m_submenuBorder = nullptr;
    LinkAdv *   m_button        = nullptr;

    QColor m_background;
    QColor m_handle;
    QColor m_handleVisible;
    QColor m_handleHidden;
    QColor m_menuShadow;
    QColor m_submenuShadow;
};

}  // namespace icL::look

#endif  // icL_look_Static
