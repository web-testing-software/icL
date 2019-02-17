#ifndef icL_context_data_js_File
#define icL_context_data_js_File

#include "js.h"



namespace icL::context::data::js {

class File : public Js
{
public:
	File(memory::InterLevel * il);

private:
	QString fileName;

protected:
	QString getFileContent();
	bool    checkArgs();

	// Context interface
public:
	bool checkPrev(const Context * context) const override;

	memory::StepType::Value execute() override;

	Context * getBeginContext() override;
	Context * getEndContext() override;
};

}  // namespace icL::context::data::js

#endif  // icL_context_data_js_File
