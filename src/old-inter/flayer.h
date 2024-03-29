#ifndef icL_inter_Flayer
#define icL_inter_Flayer

#include <icl-context/base/context.h>
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
 *  |-> inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace old::inter {

/**
 * @brief The Flayer class - flayer is a flying cursor.
 */
class Flayer : public memory::Node
{
public:
	Flayer(memory::InterLevel * il);

	/**
	 * @brief flyNextChar
	 * @return the next [[non_white]] symbol, ' ' on block end, '\0' on file end
	 */
	QChar   flyNextChar();
	QString flyKeyword();
	QString flyVarName();

	/**
	 * @brief flyNumber
	 * @return parsed int, parsed double, bool ? was int : was double
	 */
	std::tuple<int, double, bool> flyNumber();

	/**
	 * @brief getProperty
	 * @return property prefix and name
	 */
	std::pair<context::Prefix, QString> flyProperty();

	void stepForward();
	void stepBack();

	std::pair<memory::CodeFragment, bool> flyLogicFrag();

	memory::CodeFragment flyAnyExistsFrag();
	memory::CodeFragment flyCode();

	QString flyString();

	int  getPosition() const;
	void setPosition(int value);

	void setEnd(int value);

	void highlightError();

protected:
	bool flyComment();
	void findBracketPair();
	void sendWrongBrackerPair(QString & brackets, const QChar & ch);

private:
	int start    = 0;
	int position = 0;
	int end      = 0;

	const QString * source;
};

}  // namespace old::inter

#endif  // icL_inter_Flayer
