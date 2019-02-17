#ifndef icL_toolkit_panels_BasePanels
#define icL_toolkit_panels_BasePanels

#include <QObject>

/**
 * @brief The icl.toolkit.panels namespace describes the visibility og panels in
 * compact window
 */
namespace icL::toolkit::panels {

/**
 * @brief The BasePanels class contians commom properties for panels in any mode
 */
class BasePanels : public QObject
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY (bool navigationBar READ navigationBar WRITE setNavigationBar NOTIFY navigationBarChanged)
    Q_PROPERTY (bool  orientationH READ orientationH  WRITE setOrientationH  NOTIFY orientationHChanged)
    // clang-format on

public:
    explicit BasePanels(QObject * parent = nullptr);

    /**
     * @brief navigationBar is the visibility of navigation bar
     * @return the visibility of navigation bar
     */
    bool navigationBar() const;

    /**
     * @brief orientationH is the orientation switcher
     * @return the orientation (true - horizontal, false - vertical)
     */
    bool orientationH() const;

    /**
     * @brief setUp set up the state from JSON object
     * @param obj is the configuration object
     */
    virtual void setUp(const QJsonObject & obj);

    /**
     * @brief getUp get the state like JSON object
     * @return the state like JSON object
     */
    virtual QJsonObject getUp();

signals:
    void navigationBarChanged(bool navigationBar);
    void orientationHChanged(bool orientationH);

public slots:
    /**
     * @brief setNavigationBar changes the visibility of navigation bar
     * @param navigationBar is the new visibility for navigation bar
     */
    void setNavigationBar(bool navigationBar);

    /**
     * @brief setOrientationH change the orientation
     * @param orientationH is the new orientation (true - H, false - V)
     */
    void setOrientationH(bool orientationH);

private:
    bool m_navigationBar = true;
    bool m_orientationH  = true;
};

}  // namespace icL::toolkit::panels

#endif  // icL_toolkit_panels_BasePanels
