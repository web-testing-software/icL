#ifndef icL_context_data_Parameter
#define icL_context_data_Parameter

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
namespace old::context::data {

class Parameter : public Data
{
public:
	Parameter(memory::InterLevel * il, const QString & name, memory::Type type);

	const QString & name() const;
	memory::Type    type() const;

protected:
	QString      m_name;
	memory::Type m_type;

	// Context interface
public:
	bool checkPrev(const Context * context) const override;
};

}  // namespace old::context::data

#endif  // icL_context_data_Parameter
