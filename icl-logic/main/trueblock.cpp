#include "trueblock.h"

namespace vm::main::logic {

TrueBlock::TrueBlock () {

}

/**
 * @brief TrueBlock::calcResult - is always true
 * @return true
 */
bool TrueBlock::calcResult () {
	return true;
}

/**
 * @brief TrueBlock::isCross - can contains childs
 * @return false
 */
bool TrueBlock::isCross () {
	return false;
}

}
