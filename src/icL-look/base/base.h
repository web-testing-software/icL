#ifndef BASE_H
#define BASE_H

#include <QJsonObject>
#include <QObject>



namespace icL::look::base {

/**
 * @brief The Base class shares some functionality to all classes in project
 */
class Base : public QObject
{
	Q_OBJECT

public:
	Base(QObject * parent = nullptr);

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
	 * @return Color getted from hex or r/g/b/a properties
	 */
	QColor objToColor (const QJsonObject & obj);
};

}  // namespace icL::look::base

#endif  // BASE_H
