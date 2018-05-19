#ifndef ARGUMENT_H
#define ARGUMENT_H

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

}  // namespace icL::context::data

#endif  // ARGUMENT_H