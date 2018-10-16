#ifndef icL_look_BaseLook
#define icL_look_BaseLook

#include <QObject>



#define icL_dropField(x) \
	if (x != nullptr)    \
	delete x

/**
 * @brief The icL.look namespace contains a icL theme
 */
namespace icL::look {

/**
 * @brief The Base class shares some functionality to all classes in project
 */
class BaseLook : public QObject
{
	Q_OBJECT

public:
	BaseLook(QObject * parent = nullptr);

	/**
	 * @brief setUp set up the state from JSON object
	 * @param obj is the configuration object
	 */
	virtual void setUp(const QJsonObject & obj) = 0;

	/**
	 * @brief getUp get the state like JSON object
	 * @return the state like JSON object
	 */
	virtual QJsonObject getUp() = 0;

protected:
	/**
	 * @brief objToColor converts a JSON object to QColor
	 * @param obj is a JSON object
	 * @return color getted from hex or r/g/b/a properties
	 */
	QColor objToColor(const QJsonObject & obj);

	/**
	 * @brief colorToObj converts a QColor to JSON object
	 * @param color is a color to convert
	 * @return JSON object with hex field or r/g/b/a fields
	 */
	QJsonObject colorToObj(const QColor & color);
};

}  // namespace icL::look

#endif  // icL_look_BaseLook
