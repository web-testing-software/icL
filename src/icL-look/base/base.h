#ifndef BASE_H
#define BASE_H

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
};

}  // namespace icL::look::base

#endif  // BASE_H
