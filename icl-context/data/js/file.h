#ifndef FILE_H
#define FILE_H

#include "js.h"



namespace icL::context::data::js {

class File : public Js
{
public:
	File(memory::InterLevel * il, const QString &fileName);

private:
	QString fileName;

protected:
	QString getFileContent();
	bool checkArgs();

	// Context interface
public:
	bool checkPrev(const Context *context) const override;
	bool execute() override;
	Context *getBeginContext() override;
	Context *getEndContext() override;
};

}  // namespace icL::context::data::js

#endif  // FILE_H
