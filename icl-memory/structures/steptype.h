#ifndef icL_memory_StepType
#define icL_memory_StepType

#include <QObject>

namespace icL::memory::StepType {
Q_NAMESPACE

enum Value {
	NONE        = 0x0,
	MINI_STEP   = 0x1,
	COMMAND_END = 0x2,
	COMMAND_IN  = 0x6,
	COMMAND_OUT = 0x8,
	ANY         = 0xF
};

Q_ENUMS(Value)

}      // namespace icL::memory::StepType
#endif  // icL_memory_StepType
