#include "styleproxy.h"

#include <icL-look/editor/editorstyle.h>

namespace icL::editor {

StyleProxy::StyleProxy() = default;

look::EditorStyle * StyleProxy::style() {
    return m_style;
}

void StyleProxy::setStyle(look::EditorStyle * style) {
    m_style = style;
}

int StyleProxy::charW() {
    return m_style->m_charW;
}

int StyleProxy::charH() {
    return m_style->m_charH;
}

int StyleProxy::fontS() {
    return m_style->m_fontS;
}

int StyleProxy::lineS() {
    return m_style->m_lineS;
}

int StyleProxy::tabSize() {
    return m_style->m_tabSize;
}

bool StyleProxy::saveTabs() {
    return m_style->m_saveTabs;
}

int StyleProxy::divLineSBy2() const {
    return m_style->m_divLineSBy2;
}

int StyleProxy::fullLineH() const {
    return m_style->m_fullLineH;
}

}  // namespace icL::editor
