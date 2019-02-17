#include "fixer.h"

#include "../self/logic.h"
#include "line.h"

namespace icL::editor {

Fixer::Fixer() {
    linePtr.store(nullptr);
}

void Fixer::fix(Line * line) {
    if (
      linePtr.load() == nullptr || !isRunning() ||
      linePtr.load()->lineNumber() >= line->lineNumber()) {
        linePtr.store(line);
    }

    if (!isRunning()) {
        start(LowPriority);
    }
}

void Fixer::fixNow(Line * line) {
    auto * it = line;

    while (it->next() != nullptr) {
        fixOne(it);
        it = it->next();
    }

    fixOne(it);
    line->parent()->lChangeNumberOfLines(it->lineNumber());
}

void Fixer::run() {
    while (linePtr.load()->next() != nullptr) {
        fixOne(linePtr.load());

        linePtr.store(linePtr.load()->next());
    }

    auto * line = linePtr.load();

    fixOne(line);
    line->parent()->lChangeNumberOfLines(line->lineNumber());
}

void Fixer::fixOne(Line * line) {
    if (line->prev() == nullptr) {
        line->setBeginPos(0);
        line->setLineNumber(1);
    }
    else {
        line->setLineNumber(line->prev()->lineNumber() + 1);
        line->setBeginPos(
          line->prev()->beginPos() + line->prev()->length() + 1);
    }
}

}  // namespace icL::editor
