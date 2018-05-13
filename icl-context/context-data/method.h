#ifndef METHOD_H
#define METHOD_H

#include "data.h"



namespace vm::context::data {

class Method : public Data
{
public:
	Method(const QString& name);

protected:
	QString  name;
	Context* endContext;

	// Context interface
public:
	bool checkPrev(const Context* context) const override;
	bool canBeAtEnd() const override;
	bool execute() override;

	Context* getBeginContext() override;
	Context* getEndContext() override;

	bool isResultative() const override;
};

}  // namespace vm::context::data

#endif  // METHOD_H
