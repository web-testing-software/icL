#ifndef FINALY_H
#define FINALY_H

#include "item.h"



namespace icL::toolkit::tree {

class Finaly : public Item
{
public:
	Finaly(Item * parent);

	// Item interface
public:
	Item * child(int row) override;
	int    childCount() override;
};

}  // namespace icL::toolkit::tree

#endif  // FINALY_H
