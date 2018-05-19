#ifndef VAR_H
#define VAR_H

#include "value.h"



namespace icL::context::data::js {

class Var : public Value
{
public:
	Var(memory::InterLevel * il);

protected:
	std::pair<QString, QString> getArguments();

	// Context interface
public:
	bool execute() override;
};

}  // namespace icL::context::data::js

#endif  // VAR_H
