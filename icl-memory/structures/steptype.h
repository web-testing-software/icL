#ifndef icL_memory_StepType
#define icL_memory_StepType

#include <QObject>

namespace icL::memory {

class StepType
{
	Q_GADGET
public:
	StepType() = default;

	enum Value {
		None       = 0x0,
		MiniStep   = 0x1,
		CommandEnd = 0x2,
		CommandIn  = 0x6,
		CommandOut = 0x8,
		Any        = 0xF
	};
	Q_ENUM(Value)
};

}  // namespace icL::memory


#endif  // icL_memory_StepType
