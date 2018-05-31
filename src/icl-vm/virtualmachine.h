#ifndef icL_VirtualMachine
#define icL_VirtualMachine

#include <icl-inter/interpreter.h>
#include <icl-memory/interlevel/interlevel.h>


/**
 * > icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL {

class VMStack;

class VirtualMachine : public memory::VirtualMachine
{
public:
	VirtualMachine(VMStack * vms, VirtualMachine * parent, QString * source);
	virtual ~VirtualMachine() = default;

	[[nodiscard]] VirtualMachine * getParent() const;

	[[nodiscard]] memory::StepType::Value step();
	void setOnStop(std::function<void(memory::Return &)> feedback);

	void reset();
	void fullReset();

	void setFragLimits(int left, int right);

	// memory.VirtualMachine interface
	virtual void      exception(const memory::Exception & exc) override;
	virtual QString * source() override;

protected:
	void finish();

	context::Context * findExecutable();

	[[nodiscard]] memory::StepType::Value prepareNext(context::Context * next);
	[[nodiscard]] memory::StepType::Value prepareExecutable(
	  context::Context * executable);

	void destroy(context::Context * executable);

private:
	memory::InterLevel il;
	inter::Interpreter interpreter;

	VirtualMachine * parent;
	QString *        m_source;
	bool             waiting_mode;

	context::Context * last_context = nullptr;
	memory::Return     r_result;

	bool running        = true;
	bool commandParsing = true;

	std::function<void(memory::Return &)> onStop = nullptr;

	int code_begin, code_end;
};

}  // namespace icL

#endif  // icL_VirtualMachine
