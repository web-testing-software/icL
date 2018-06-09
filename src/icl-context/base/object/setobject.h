#ifndef METAOBJECT_H
#define METAOBJECT_H


#include "set.h"

#include <icl-memory/state/datastate.h>

namespace icL::context::object {

class SetObject
	: public object::Object
	, public memory::DataStateInterface
{
public:
	SetObject();


	// DataStateInterface interface
	void setValue(const QString & name, const QVariant & value) override;

	bool         contains(const QString & name) override;
	memory::Type getType(const QString & name) override;
	bool         checkType(const QString & name, memory::Type & type) override;
	QVariant     getValue(const QString & name) override;

private:
	memory::SetObjPtr data;
};

}  // namespace icL::context::object

#endif  // METAOBJECT_H
