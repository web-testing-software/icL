#ifndef icL_context_data_Property
#define icL_context_data_Property

#include "data.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |-> data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::context::data {

class Property : public Data
{
public:
	Property(memory::InterLevel * il, Prefix prefix, const QString & name);

protected:
	Prefix prefix;
	QString name;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
	bool canBeAtEnd() const override;
	bool isExecutable() const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;

	bool isResultative() const override;
};

}  // namespace icL::context::data

#endif  // icL_context_data_Property
