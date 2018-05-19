#ifndef CROSSFIRE_H
#define CROSSFIRE_H

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

#endif  // CROSSFIRE_H
