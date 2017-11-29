#ifndef COMMENT_H
#define COMMENT_H

#include "../../parser.h"



namespace vm {
namespace language {
namespace control {
namespace comment {

void parse (vm::main::Driver &drive);

void runDelimiter (vm::main::Driver &drive);
void runLine (vm::main::Driver &drive);
void runMultiline (vm::main::Driver &drive);

}
}
}
}

#endif // COMMENT_H
