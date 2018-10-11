#ifndef FOLDER_H
#define FOLDER_H

#include "item.h"

#include <QList>



namespace icL::toolkit::tree {

class Folder : public Item
{
public:
	Folder(Item * parent);

	// Item interface
public:
	Item * child(int row) override;
	int    columnCount() override;
	int    childCount() override;

protected:
	QList<Item *> children;

public:
	friend class Item;
};

}  // namespace icL::toolkit::tree

#endif  // FOLDER_H
