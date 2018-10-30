#ifndef icL_editor_Alpha
#define icL_editor_Alpha

#include <qdatetime.h>



namespace icL::editor {

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
	float lastAlpha;
	float nextAlpha;

	QTime last_time;
	int   interval_in_ms = 0;

	bool speed_up_fadein = true;
	bool need_update     = false;
};

}  // namespace icL::editor

#endif  // icL_editor_Alpha
