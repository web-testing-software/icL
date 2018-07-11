#ifndef icL_memory_WebElement
#define icL_memory_WebElement

#include <QString>
#include <QVariant>


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

class WebElement
{
public:
	virtual QString variable()         = 0;
	virtual QString nthVariable(int n) = 0;
	virtual int     count()            = 0;
};

struct IclElement : public WebElement
{
	QString m_selector;
	// The name of variable in which we will stock data in javascript
	QString m_variable;
	int     m_count    = 0;

	// WebElement interface
	QString variable() override;
	QString nthVariable(int n) override;
	int     count() override;
};

struct W3cElement : public WebElement {
	QStringList variables;

	// WebElement interface
	QString variable() override;
	QString nthVariable(int n) override;
	int     count() override;

	static QString indentifier;
};

}  // namespace icL::memory

Q_DECLARE_METATYPE(icL::memory::IclElement);
Q_DECLARE_METATYPE(icL::memory::W3cElement);

#endif  // icL_memory_WebElement
