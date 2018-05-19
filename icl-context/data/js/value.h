#ifndef VALUE_H
#define VALUE_H

#include "js.h"



namespace icL::context::data::js {

class Value : public Js
{
public:
	Value(memory::InterLevel * il);

	QString getCode ();

	// Context interface
public:
	bool checkPrev(const Context *context) const override;
	Context *getBeginContext() override;
	Context *getEndContext() override;
	bool isResultative() const override;
};

}  // namespace icL::context::data::js

#endif  // VALUE_H
