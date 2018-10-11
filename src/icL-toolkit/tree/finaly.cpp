#include "finaly.h"

namespace icL::toolkit::tree {

Finaly::Finaly(Item * parent)
	: Item(parent) {}

Item * Finaly::child(int row) {
	return nullptr;
}

int Finaly::childCount() {
	return 0;
}

}  // namespace icL::toolkit::tree
