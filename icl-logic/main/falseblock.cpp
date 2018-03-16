#include "falseblock.h"

namespace vm::main::logic {

FalseBlock::FalseBlock () {

}

/**
 * @brief FalseBlock::calcResult - the false constant is always false
 * @return false
 */
bool FalseBlock::calcResult () {
	return false;
}

/**
 * @brief FalseBlock::isCross - it cann't have children
 * @return false
 */
bool FalseBlock::isCross () {
	return false;
}

}
