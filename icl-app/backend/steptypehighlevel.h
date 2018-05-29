#ifndef icL_StepTypeHighLevel
#define icL_StepTypeHighLevel

#include <icl-memory/structures/steptype.h>

#include <QObject>
#include <qqml.h>

namespace icL::app {

class StepTypeHighLevel : public icL::memory::StepType
{
	Q_GADGET

public:
	Q_ENUM(Value)

public:
	StepTypeHighLevel();
};

}  // namespace icL::app

#endif  // icL_StepTypeHighLevel
