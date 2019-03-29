#ifndef icL_vm_Mock
#define icL_vm_Mock

#include <icL-il/main/vmlayer.h>
#include <icL-il/structures/signal.h>



namespace icL::vm {

class Mock : public il::VMLayer
{
public:
    Mock() = default;

    // VMLayer interface
public:
    void signal(const il::Signal & signal) override;
    void addDescription(const QString & description) override;
    void markStep(const QString & name) override;
    void markTest(const QString & name) override;
    void break_() override;
    void continue_() override;
    void return_(const QVariant & value) override;
    bool hasOkState() override;

    memory::Memory * getMemory() override;

private:
    il::Signal m_signal;
};

}  // namespace icL::vm

#endif  // icL_vm_Mock
