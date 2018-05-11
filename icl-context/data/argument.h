#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "data.h"



namespace vm::context::data {

class Argument : public Data
{
public:
	Argument (const QString &name, memory::Type type);

	const QString& name() const;
	memory::Type type() const;

protected:
	QString m_name;
	memory::Type m_type;

	// Context interface
public:
	bool checkPrev(const Context *context) const override;
};

} // namespace

#endif // ARGUMENT_H
