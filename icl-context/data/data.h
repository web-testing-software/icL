#ifndef DATA_H
#define DATA_H

#include <context.h>


namespace vm::context::data {

class Data : public Context
{
public:
	Data ();

	// Context interface
public:
	bool isExecuable () override;
};

}

#endif // DATA_H
