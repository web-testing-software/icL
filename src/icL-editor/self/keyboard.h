#ifndef icL_editor_Keyboard
#define icL_editor_Keyboard

#include "history.h"



namespace icL::editor {

/**
 * @brief The Keyboard class releases the interaction beetwen editor and
 * keyboard
 */
class Keyboard : public History
{
    Q_OBJECT
public:
    explicit Keyboard(QQuickItem * parent = nullptr);

signals:

public slots:

    // QQuickItem interface
protected:
    void keyPressEvent(QKeyEvent * event) override;
    //	void keyReleaseEvent(QKeyEvent * event) override;

private:
    /**
     * @brief functionKey handles a function key without modifirs
     */
    void functionKey(QKeyEvent * event);

    /**
     * @brief functionShiftKey handles Shift + function key
     */
    void functionShiftKey(QKeyEvent * event);

    /**
     * @brief functionCtrlKey handles Ctrl + function key
     */
    void functionCtrlKey(QKeyEvent * event);

    /**
     * @brief functionAltKey handles Alt + function key
     */
    void functionAltKey(QKeyEvent * event);

    /**
     * @brief functionShiftCtrlKey handles Shift + Ctrl + function key
     */
    void functionShiftCtrlKey(QKeyEvent * event);

    /**
     * @brief functionShiftAltKey handles Shift + Ctrl + function key
     */
    void functionShiftAltKey(QKeyEvent * event);

    /**
     * @brief functionCtrlAltKey handles Ctrl + Alt + function key
     */
    void functionCtrlAltKey(QKeyEvent * event);

    /**
     * @brief functionCtrlAltShiftKey handles Ctrl + Alt + Shift + function key
     */
    void functionCtrlAltShiftKey(QKeyEvent * event);

    /**
     * @brief anyKey handles any key without modifiers
     */
    void anyKey(QKeyEvent * event);

    /**
     * @brief anyShiftKey handles Shift + any key
     */
    void anyShiftKey(QKeyEvent * event);

    /**
     * @brief anyCtrlKey handles Ctrl + any key
     */
    void anyCtrlKey(QKeyEvent * event);

    /**
     * @brief anyAltKey handles Alt + any key
     */
    void anyAltKey(QKeyEvent * event);

    /**
     * @brief anyShiftCtrlKey handles Shift + Ctrl + any key
     */
    void anyShiftCtrlKey(QKeyEvent * event);

    /**
     * @brief anyShiftAltKey handles Shift + Alt + any key
     */
    void anyShiftAltKey(QKeyEvent * event);

    /**
     * @brief anyCtrlAltKey handles Ctrl + Alt + any key
     */
    void anyCtrlAltKey(QKeyEvent * event);

    /**
     * @brief anyCtrlAltShiftKey handles Ctrl + Alt + Shift + any key
     */
    void anyCtrlAltShiftKey(QKeyEvent * event);
};

}  // namespace icL::editor

#endif  // icL_editor_Keyboard
