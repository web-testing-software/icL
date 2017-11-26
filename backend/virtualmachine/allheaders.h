#ifndef ALLHEADERS_H
#define ALLHEADERS_H

#include "language/control/singleshot.h"
#include "language/control/multishot.h"
#include "language/control/comment.h"
#include "language/localmemory/readl.h"
#include "language/localmemory/writel.h"
#include "language/statestorange/reads.h"
#include "language/statestorange/writes.h"
#include "language/constant/readc.h"
#include "language/booloperator/logical.h"
#include "language/booloperator/equal.h"
#include "language/booloperator/notequal.h"
#include "language/booloperator/stringlist.h"
#include "driver/navigation/navigation.h"
#include "driver/navigation/wainting.h"
#include "driver/managecontent/frames.h"
#include "javascript/basejs/runjs.h"
#include "javascript/basejs/get.h"
#include "javascript/basejs/set.h"
#include "javascript/dom/findelements.h"
#include "javascript/dom/filterelements.h"
#include "javascript/dom/elementstest.h"
#include "input/mouse/complexeventm.h"
#include "input/keyboard/complexeventk.h"
#include "database/basic/output.h"
#include "database/basic/editing.h"
#include "debugger/basic/testing.h"

struct Level3Container {
	vm::language::control::singleshot::Singleton single_shot;
	vm::language::control::comment::Singleton comment;
	vm::language::localmemory::read::Singleton readl;
	vm::language::localmemory::write::Singleton writel;
	vm::language::statestorange::read::Singleton reads;
	vm::language::statestorange::write::Singleton writes;
	vm::language::constant::read::Singleton readc;
	vm::language::booloperator::logical::Singleton logical;
	vm::language::booloperator::equal::Singleton equal;
	vm::language::booloperator::notequal::Singleton notequal;
	vm::language::booloperator::stringlist::Singleton stringlist;
	vm::driver::navigation::navigation::Singleton navigation;
	vm::driver::navigation::wainting::Singleton wainting;
	vm::driver::managecontent::frames::Singleton frames;
	vm::javascript::basejs::runjs::Singleton runjs;
	vm::javascript::basejs::get::Singleton get;
	vm::javascript::basejs::set::Singleton set;
	vm::javascript::dom::findelements::Singleton find_elements;
	vm::javascript::dom::filterelements::Singleton filter_elements;
	vm::javascript::dom::elementstest::Singleton elements_test;
	vm::input::mouse::complexevent::Singleton mouse_complex;
	vm::input::keyboard::complexevent::Singleton keyboard_complex;
	vm::database::basic::output::Singleton output;
	vm::database::basic::editing::Singleton edititng;
	vm::debugger::basic::testing::Singleton focus;
};

#endif // ALLHEADERS_H
