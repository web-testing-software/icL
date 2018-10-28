#ifndef icL_editor_Fixer
#define icL_editor_Fixer

#include <QThread>



namespace icL::editor {

class Line;

class Fixer : public QThread
{
public:
	Fixer();

	/**
	 * @brief fix fixes the line in separated thread
	 * @param line is the first line which needs fix
	 */
	void fix(Line * line);

	/**
	 * @brief fixNow fixes the line in current thread
	 * @param line is the first line which needs fix
	 */
	void fixNow(Line * line);

	// QThread interface
protected:
	void run() override;

private:
	void fixOne(Line * line);

private:
	QAtomicPointer<Line> linePtr;
};

}  // namespace icL::editor

#endif  // icL_editor_Fixer
