#ifndef icL_editor_Fixer
#define icL_editor_Fixer

#include <QThread>



namespace icL::editor {

class Line;

/**
 * @brief The Fixer class fixes the line numbers and absolute position of lines
 * begins.
 *
 * If the requested line has a line number smaller or equal with current the
 * iterator will be moved to it. This class doesn't edit the logic model. All
 * changes in logic model made by other threads must be forward safe. The
 * iterator can be changed in run time. This class is thread safe.
 */
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
	/**
	 * @brief fixOne fixes a line right now
	 * @param line is the line to fix
	 */
	void fixOne(Line * line);

private:
	/// @brief the pointer to current line like an atomic pointer
	QAtomicPointer<Line> linePtr;
};

}  // namespace icL::editor

#endif  // icL_editor_Fixer
