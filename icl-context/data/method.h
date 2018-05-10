#ifndef METHOD_H
#define METHOD_H

#include "data.h"



namespace vm::context::data {

class Method : public Data
{
public:
	Method ();

protected:
	QString name;
	Context *endContext;

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	bool execute () override;

	Context* getBeginContext () override;
	Context* getEndContext () override;
};

} // namespace

#endif // METHOD_H
