#ifndef COMMENT_H
#define COMMENT_H

#include "../../parser.h"



namespace vm::language::control::comment {

void parse (main::Driver &drive);

void runDelimiter (main::Driver &drive);
void runLine (main::Driver &drive);
void runMultiline (main::Driver &drive);

}

#endif // COMMENT_H
