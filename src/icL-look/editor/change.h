#ifndef CHANGE_H
#define CHANGE_H

#include "../base/baselook.h"

#include <QColor>

namespace icL::look {

class Change : public BaseLook
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(QColor changed READ changed WRITE setChanged NOTIFY changedChanged)
    Q_PROPERTY(QColor   saved READ saved   WRITE setSaved   NOTIFY savedChanged)
    Q_PROPERTY(QColor phantom READ phantom WRITE setPhantom NOTIFY phantomChanged)
    // clang-format on

public:
    explicit Change(QObject * parent = nullptr);

    /**
     * @brief changed is the color of changed lines
     * @return the color for changed lines
     */
    QColor changed() const;

    /**
     * @brief saved is the color of saved lines
     * @return the color for saved lines
     */
    QColor saved() const;

    /**
     * @brief phantom is the color for phantom lines
     * @return the color for phantom lines
     */
    QColor phantom() const;

signals:
    void changedChanged(QColor changed);
    void savedChanged(QColor saved);
    void phantomChanged(QColor phantom);

public slots:
    /**
     * @brief setChanged sets the color for changed lines
     * @param changed is the new color for changed lines
     */
    void setChanged(const QColor & changed);

    /**
     * @brief setSaved sets the color for saved lines
     * @param saved is the new color for changed lines
     */
    void setSaved(const QColor & saved);

    /**
     * @brief setPhantom sets the color of phantom lines
     * @param phantom is the new color for phantoms lines
     */
    void setPhantom(const QColor & phantom);

    // BaseLook interface
public:
    void setUp(const QJsonObject & obj) override;

    QJsonObject getUp() override;

private:
    QColor m_changed;
    QColor m_saved;
    QColor m_phantom;
};

}  // namespace icL::look

#endif  // CHANGE_H
