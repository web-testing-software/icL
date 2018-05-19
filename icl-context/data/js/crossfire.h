#ifndef icL_context_data_js_Crossfire
#define icL_context_data_js_Crossfire

#include "file.h"


namespace icL::context::data::js {

class Crossfire : public File
{
public:
	Crossfire(memory::InterLevel * il, const QString &fileName);

	// Context interface
public:
	bool execute() override;
};

}  // namespace icL::context::data::js

#endif  // icL_context_data_js_Crossfire
