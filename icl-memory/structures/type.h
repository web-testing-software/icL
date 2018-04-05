#ifndef TYPE_H
#define TYPE_H

namespace vm::memory {

enum class Type {
	NODATA,
	BOOLEAN,
	INT,
	DOUBLE,
	STRING,
	LIST,
	ELEMENT
};

}

#endif // TYPE_H
