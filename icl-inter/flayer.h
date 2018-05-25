#ifndef icL_inter_Flayer
#define icL_inter_Flayer

#include <icl-memory/interlevel/node.h>

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
 *  |- @namespace inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace icL::inter::_private {

/**
 * @brief The Flayer class - flayer is a flying cursor.
 */
class Flayer : public memory::Node
{
public:
	Flayer(memory::InterLevel * il, const QString * source);

	QChar   getNextChar();
	QString getKeyword();
	QString getVarName();

	void stepBack();

	int  getPosition() const;
	void setPosition(int value);

	void setEnd(int value);

protected:
	bool flyComment();

private:
	int             position;
	int             end;
	const QString * source;
};

}  // namespace icL::inter::_private

#endif  // icL_inter_Flayer
