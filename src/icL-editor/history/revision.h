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
    virtual ~Revision() = default;

    /**
     * @brief undo undos the changes, descripted in the revision
     */
    virtual void undo(Logic * logic) = 0;

    /**
     * @brief redo redos the changes, descripted in the revision
     */
    virtual void redo(Logic * logic) = 0;

    // double-linked list

    /**
     * @brief prev gets the prev element in edit history
     * @return the prev element in edit history
     */
    Revision * prev();

    /**
     * @brief next gets the next element in edit history
     * @return the next element in edit history
     */
    Revision * next();

    /**
     * @brief alt get the alternative next element in edit history
     * @return the alternative next element in edit history
     */
    Revision * alt();

    /**
     * @brief setPrev sets the prev element in edit history
     * @param prev is the new prev element in edit history
     */
    void setPrev(Revision * prev);

    /**
     * @brief setNext sets the next element in edit history
     * @param next is the new next element in edit history
     */
    void setNext(Revision * next);

    /**
     * @brief setAlt sets the alternative element in edit history
     * @param alt is the new alternative element in edit history
     */
    void setAlt(Revision * alt);

private:
    /// \brief m_prev is the prev element in edit history
    Revision * m_prev = nullptr;

    /// \brief m_next is the next element in edit history
    Revision * m_next = nullptr;

    /// \brief m_alt is the next alternative element in edit history
    Revision * m_alt = nullptr;
};

}  // namespace icL::editor

#endif  // icL_editor_Revision
