#ifndef icL_editor_Alpha
#define icL_editor_Alpha

#include <qdatetime.h>



namespace icL::editor {

/**
 * @brief The Alpha class permits to animate a float property
 */
class Alpha
{
public:
    Alpha() = default;

    /**
     * @brief currentAlpha is the current alpha value
     */
    float currentAlpha;

    /**
     * @brief nextValue is the requested value
     * @return the requested value
     */
    float nextValue();

    /**
     * @brief setCurrentAlpha set the current value with animation
     * @param value is the new alpha value
     */
    void setCurrentAlpha(float value);

    /**
     * @brief forceSetCurrentAlpha set the current value without animation
     * @param value is the new alpha value
     */
    void forceSetCurrentAlpha(float value);

    /**
     * @brief setInterval set the time interval of animation
     * @param interval is the new time interval of animation
     */
    void setInterval(int interval);

    /**
     * @brief setSpeedUpOnFadeIn speeds up the increasing of value
     * @param value true to speed up, false disable
     */
    void setSpeedUpOnFadeIn(bool value);

    /**
     * @brief update update the value now
     * @return bool if the value was changed, otherwise false
     */
    bool update();

private:
    /**
     * @brief transition make a special transition for opacity of cursor
     * @param x - is the linear interpoleted value
     * @return the smooth interpolated fixed value
     */
    qreal transition(qreal x);


private:
    /// @brief is the last alpha value
    float lastAlpha;

    /// @brief is the next alpha value (value to transition to)
    float nextAlpha;

    /// @brief is the time of last value change request
    QTime lastTime;

    /// @brief is the interval of transition in ms
    int intervalInMs = 0;

    /// @brief speeds up the increasing of value
    bool speedUpFadein = true;

    /// @brief confirms that is necessary an update now
    bool needUpdate = false;
};

}  // namespace icL::editor

#endif  // icL_editor_Alpha
