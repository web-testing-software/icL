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
	 * @brief objToColor converts a JSON object to QColor
	 * @param obj is a JSON object
	 * @return Color getted from hex or r/g/b/a properties
	 */
	QColor objToColor (const QJsonObject & obj);
};

}  // namespace icL::look::base

#endif  // BASE_H
