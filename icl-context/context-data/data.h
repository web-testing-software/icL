#ifndef DATA_H
#define DATA_H

#include <context-base/context.h>


/**
 * vm
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
namespace vm::context::data {

class Data : public Context
{
public:
	Data();

	// Context interface
public:
	bool canBeAtEnd() const override;
	bool isExecuable() const override;
};

}  // namespace vm::context::data

#endif  // DATA_H
