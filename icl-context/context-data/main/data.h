#ifndef DATA_H
#define DATA_H

#include <icl-context/context-base/context.h>


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

class Data : public Context
{
public:
	Data(memory::InterLevel * il);

	// Context interface
public:
	bool canBeAtEnd() const override;
	bool isExecuable() const override;
};

}  // namespace icL::context::data

#endif  // DATA_H
