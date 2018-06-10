#ifndef icL_memory_WebElement
#define icL_memory_WebElement

#include <QString>
#include <QVariant>

#include <memory>

/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '-> memory
 */
namespace icL::memory {


struct Element
{
	QString selector = "";
	// The name of variable in which we will stock data in javascript
	QString variable = "";
	int     count    = 0;
};

struct ElementPtr {
	std::shared_ptr<Element> el;
};

}  // namespace icL::memory

Q_DECLARE_METATYPE(icL::memory::ElementPtr);

#endif  // icL_memory_WebElement
