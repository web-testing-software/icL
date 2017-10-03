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
#include "debugger/basic/focus.h"

struct Level3Container {
	VM::Language::Control::SingleShot::Singleton single_shot;
	VM::Language::Control::Comment::Singleton comment;
	VM::Language::LocalMemory::Read::Singleton readl;
	VM::Language::LocalMemory::Write::Singleton writel;
	VM::Language::StateStorange::Read::Singleton reads;
	VM::Language::StateStorange::Write::Singleton writes;
	VM::Language::Constant::Read::Singleton readc;
	VM::Language::BoolOperator::Logical::Singleton logical;
	VM::Language::BoolOperator::Equal::Singleton equal;
	VM::Language::BoolOperator::NotEqual::Singleton notequal;
	VM::Language::BoolOperator::StringList::Singleton stringlist;
	VM::Driver::Navigation::Navigation::Singleton navigation;
	VM::Driver::Navigation::Wainting::Singleton wainting;
	VM::Driver::ManageContent::Frames::Singleton frames;
	VM::JavaScript::BaseJS::RunJS::Singleton runjs;
	VM::JavaScript::BaseJS::Get::Singleton get;
	VM::JavaScript::BaseJS::Set::Singleton set;
	VM::JavaScript::DOM::FindElements::Singleton find_elements;
	VM::JavaScript::DOM::FilterElements::Singleton filter_elements;
	VM::JavaScript::DOM::ElementsTest::Singleton elements_test;
	VM::Input::Mouse::ComplexEvent::Singleton mouse_complex;
	VM::Input::Keyboard::ComplexEvent::Singleton keyboard_complex;
	VM::DataBase::Basic::Output::Singleton output;
	VM::DataBase::Basic::Editing::Singleton edititng;
	VM::Debugger::Basic::Focus::Singleton focus;
};

#endif // ALLHEADERS_H
