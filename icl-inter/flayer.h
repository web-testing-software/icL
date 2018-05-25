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
	Flayer(const QString *source);

	QChar getNextChar();
	QString getKeyword();
	QString getVarName();

	void stepBack();

	int getPosition() const;
	void setPosition(int value);

	void setEnd(int value);

protected:
	void flyComment();

private:
	int position;
	int end;
	const QString *source;
};

}  // namespace icL::inter::_private

#endif  // icL_inter_Flayer
