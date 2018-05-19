#ifndef icL_context_data_Method
#define icL_context_data_Method

#include "data.h"


/**
 *  icL
 *  |- app
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- @namespace data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::data {

class Method : public Data
{
public:
	Method(memory::InterLevel * il, const QString & name);

protected:
	QString   name;
	Context * endContext;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;
	bool execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;

	bool isResultative() const override;
};

}  // namespace icL::context::data

#endif  // icL_context_data_Method
