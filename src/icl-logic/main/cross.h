#ifndef icL_logic_cross_Cross
#define icL_logic_cross_Cross

#include "logic.h"


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |-> logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::logic::cross {

/**
 * @brief The Cross class - this is a block with 2 children (Logic*
 * type)
 */
class Cross : public Logic
{
public:
	Cross(memory::InterLevel * il);
	~Cross();

	bool         canAcceptBlock();
	virtual void giveBlock(Logic * block);

protected:
	Logic * block1 = nullptr;
	Logic * block2 = nullptr;
	bool    value1 = false, value2 = false, value1getted = false,
		 value2getted = false;


	// Logic interface
public:
	bool isCross() override;
	bool checkIntegrity() override;
	void resetResultValue() override;

	bool    needCast() override;
	Logic * castNow() override;
	bool    step() override;

	bool calcResult() override;
};

}  // namespace icL::logic::cross

#endif  // icL_logic_cross_Cross
