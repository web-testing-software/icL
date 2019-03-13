#ifndef icL_context_data_Data
#define icL_context_data_Data

#include <icl-context/base/context.h>


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

class Data : public Context
{
public:
	Data(memory::InterLevel * il);

	// Context interface
public:
	bool canBeAtEnd() const override;
	bool isExecutable() const override;
};

}  // namespace old::context::data

#endif  // icL_context_data_Data
