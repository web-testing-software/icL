#include "look.h"

#include "../editor/editor.h"
#include "../session/sessionwindow.h"
#include "../start/startwindow.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

namespace icL::look {

Look::Look(QObject * parent)
    : BaseLook(parent) {
    m_editor  = new Editor(this);
    m_session = new SessionWindow(this);
    m_start   = new StartWindow(this);
}

Look::~Look() {
    if (source == nullptr) {
        delete m_editor;
        delete m_session;
        delete m_start;
    }
}

StartWindow * Look::start() const {
    return m_start;
}

SessionWindow * Look::session() const {
    return m_session;
}

Editor * Look::editor() const {
    return m_editor;
}

QString Look::path() const {
    return *m_path;
}

void Look::clone(Look * look) {
    auto * old_path    = m_path;
    auto * old_editor  = m_editor;
    auto * old_session = session();
    auto * old_start   = m_start;

    m_path    = look->m_path;
    m_editor  = look->m_editor;
    m_session = look->m_session;
    m_start   = look->m_start;

    emit pathChanged(*m_path);
    emit editorChanged(m_editor);
    emit sessionChanged(m_session);
    emit startChanged(m_start);

    old_editor->setParent(nullptr);
    old_session->setParent(nullptr);
    old_start->setParent(nullptr);

    delete old_path;
    delete old_editor;
    delete old_session;
    delete old_start;

    source = look;
}

bool Look::loadConf(const QString & path, bool editorOnly) {
    QFile         file(path);
    QTextStream   stream(&file);
    QJsonDocument doc;

    if (!file.open(QFile::ReadOnly)) {
        return false;
    }

    editorOnly ? editorConfFilePath : confFilePath = path;


    QString content = stream.readAll();
    doc             = QJsonDocument::fromJson(content.toUtf8());

    if (!doc.isObject()) {
        doc = QJsonDocument::fromJson(QString("{}").toUtf8());
    }

    QJsonObject obj = doc.object();

    if (editorOnly) {
        obj.remove("session");
        obj.remove("start");
    }
    else {
        QString path = obj.value("path").toString();

        if (!path.isEmpty()) {
            *m_path = path;

            emit pathChanged(path);
        }
    }

    setUp(obj);

    file.close();

    return true;
}

bool Look::saveConf(bool editorOnly) {
    QFile         file(editorOnly ? editorConfFilePath : confFilePath);
    QTextStream   stream(&file);
    QJsonDocument doc;

    if (!file.open(QFile::WriteOnly)) {
        return false;
    }

    QJsonObject obj = getUp();

    if (editorOnly) {
        obj.remove("session");
        obj.remove("start");
    }
    else {
        obj["path"] = *m_path;
    }

    doc.setObject(obj);

    stream << doc.toJson(QJsonDocument::Indented);

    file.close();
    return true;
}

void Look::setUp(const QJsonObject & obj) {
    m_editor->setUp(obj.value("editor").toObject());
    m_session->setUp(obj.value("session").toObject());
    m_start->setUp(obj.value("start").toObject());
}

QJsonObject Look::getUp() {
    return {{"editor", m_editor->getUp()},
            {"session", m_session->getUp()},
            {"start", m_start->getUp()}};
}

void Look::setPath(const QString & path) {
    if (*m_path == path)
        return;

    *m_path = path;
    emit pathChanged(path);

    if (source) {
        emit source->pathChanged(path);
    }
}

}  // namespace icL::look
