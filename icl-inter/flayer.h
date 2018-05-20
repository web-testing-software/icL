#ifndef icL_inter_Flayer
#define icL_inter_Flayer

#include <QObject>

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
class Flayer
{
public:
	Flayer();
	~Flayer();

private:
	int begin;
	int end;
};

}  // namespace icL::inter::_private

#endif  // icL_inter_Flayer
