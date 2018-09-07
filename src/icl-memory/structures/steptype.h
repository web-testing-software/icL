#ifndef icL_memory_StepType
#define icL_memory_StepType

#include <QObject>

namespace icL::memory::StepType {
Q_NAMESPACE

enum Value {
	None       = 0x0,
	MiniStep   = 0x1,
	CommandEnd = 0x2,
	CommandIn  = 0x6,
	CommandOut = 0x8,
	Any        = 0xF
};

Q_ENUMS(Value)

}  // namespace icL::memory::StepType
#endif  // icL_memory_StepType
