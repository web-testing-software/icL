#ifndef COMMENT_H
#define COMMENT_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace control {
namespace comment {

void parse (vm::system::Driver &driver);

// This class is needed for compability with QML
class Singleton {

public:
	static void runDelimiter (vm::system::Driver &driver);
	static void runLine (vm::system::Driver &driver);
	static void runMultiline (vm::system::Driver &driver);
};

}
}
}
}

#endif // COMMENT_H
