#ifndef COMMENT_H
#define COMMENT_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace control {
namespace comment {

void parse (vm::main::Driver &drive);

class Singleton {

public:
	static void runDelimiter (vm::main::Driver &drive);
	static void runLine (vm::main::Driver &drive);
	static void runMultiline (vm::main::Driver &drive);
};

}
}
}
}

#endif // COMMENT_H
