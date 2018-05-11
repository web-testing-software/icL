#ifndef PROPERTY_H
#define PROPERTY_H

#include "data.h"



namespace vm::context::data {

class Property : public Data
{
public:
	Property (const QString &name);

protected:
	QString name;

	// Context interface
public:
	bool checkPrev (const Context *context) const override;
	bool canBeAtEnd () const override;
	bool execute () override;

	Context* getBeginContext () override;
	Context* getEndContext () override;
};

} // namespace

#endif // PROPERTY_H
