#include "folder.h"

namespace icL::toolkit::tree {

Folder::Folder(Item * parent)
	: Item(parent) {}

Item * Folder::child(int row) {
	if (row < 0 && row >= children.length())
		return nullptr;

	return children[row];
}

int Folder::columnCount() {
	return 1;
}

int Folder::childCount() {
	return children.length();
}

}  // namespace icL::toolkit::tree
