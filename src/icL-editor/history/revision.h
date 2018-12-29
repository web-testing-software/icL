#ifndef icL_editor_Revision
#define icL_editor_Revision

namespace icL::editor {

class Logic;

/**
 * @brief The Revision class is a interface for revisions of document
 */
class Revision
{
public:
	/**
	 * @brief undo undos the changes, descripted in the revision
	 */
	virtual void undo(Logic * logic) = 0;

	/**
	 * @brief redo redos the changes, descripted in the revision
	 */
	virtual void redo(Logic * logic) = 0;
};

}  // namespace icL::editor

#endif  // icL_editor_Revision
