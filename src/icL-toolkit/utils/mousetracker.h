#ifndef icL_toolkit_utils_MouseTracker
#define icL_toolkit_utils_MouseTracker

#include <QPoint>
#include <QThread>

/**
 * @brief The icL.toolkit.utils namespace contains useful classes
 */
namespace icL::toolkit::utils {

/**
 * @brief The MouseTracker class track the mouse in global mode
 */
class MouseTracker : public QThread
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(bool   tracking READ tracking NOTIFY trackingChanged)
    Q_PROPERTY(QPoint position READ position NOTIFY posittionChanged)
    // clang-format on

public:
    explicit MouseTracker(QObject * parent = nullptr);

    /**
     * @brief tracking is the active tracking switcher
     * @return true is now is tracking, otherwise false
     */
    bool tracking() const;

    /**
     * @brief position is the current position of mouse
     * @return the current position of mouse
     */
    QPoint position() const;

    /**
     * @brief startTracking starts the tracking process
     * @return the current position of mouse
     */
    Q_INVOKABLE QPoint startTracking();

    /**
     * @brief stopTracking stops the tracking process
     * @return the last position of cursor
     */
    Q_INVOKABLE QPoint stopTracking();

signals:
    void trackingChanged(bool tracking);
    void posittionChanged(QPoint position);

public slots:

    // QThread interface
protected:
    void run() override;

private:
    bool   m_tracking{};
    QPoint m_position;
};

}  // namespace icL::toolkit::utils

#endif  // icL_toolkit_utils_MouseTracker
