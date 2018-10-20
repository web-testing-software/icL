#include "line.h"

#include "../self/logic.h"
#include "fragment.h"

#include <QStaticText>
#include <QTextStream>

namespace icL::editor {

Line::Line(Logic * parent)
	: QObject(parent) {
	m_parent = parent;
}

Fragment * Line::first() const {
	return m_first;
}

Line * Line::next() const {
	return m_next;
}

Line * Line::prev() const {
	return m_prev;
}

uint8_t Line::length() const {
	return m_length;
}

int32_t Line::beginPos() const {
	return m_beginPos;
}

int16_t Line::lineNumber() const {
	return m_lineNumber;
}

bool Line::visible() const {
	return m_visible;
}

const QString & Line::getText() {
	if (!m_isChanged) {
		return content;
	}

	auto * it = m_first;

	content.clear();
	content.reserve(m_length);

	content += QString('\t', it->spaces() / 4);
	content += QString(' ', it->spaces() % 4);
	content += it->displayText();
	it = it->next();

	while (it != nullptr) {
		content += QString(' ', it->spaces());
		content += it->displayText();
	}

	return content;
}

bool Line::isChanged() {
	return m_isChanged;
}

void Line::save(QTextStream * stream) {
	(*stream) << getText();
	m_isChanged = false;
}

Logic * Line::parent() const {
	return m_parent;
}

QStaticText * Line::getCache() {
	return cache;
}

void Line::setFirst(Fragment * first) {
	if (m_first == first)
		return;

	m_first = first;
	m_length = first->length();
	emit firstChanged(m_first);
}

void Line::setNext(Line * next) {
	if (m_next == next)
		return;

	m_next = next;
	emit nextChanged(m_next);
}

void Line::setPrev(Line * prev) {
	if (m_prev == prev)
		return;

	m_prev = prev;
	emit prevChanged(m_prev);
}

void Line::setBeginPos(int32_t beginPos) {
	if (m_beginPos == beginPos)
		return;

	m_beginPos = beginPos;
	emit beginPosChanged(m_beginPos);
}

void Line::setLineNumber(int16_t lineNumber) {
	if (m_lineNumber == lineNumber)
		return;

	if (cache != nullptr) {
		cache->setText(QString::number(lineNumber));
	}

	m_lineNumber              = lineNumber;
	m_charsNumberInLineNumber = 0;

	if (lineNumber < 10) {
		m_charsNumberInLineNumber = 1;
	}
	else if (lineNumber < 100) {
		m_charsNumberInLineNumber = 2;
	}
	else if (lineNumber < 1000) {
		m_charsNumberInLineNumber = 3;
	}
	else if (lineNumber < 10000) {
		m_charsNumberInLineNumber = 4;
	}
	else {
		m_charsNumberInLineNumber = 5;
	}

	qDebug() << lineNumber << m_charsNumberInLineNumber;

	emit lineNumberChanged(m_lineNumber);
}

void Line::setVisible(bool visible) {
	if (m_visible == visible)
		return;

	if (visible) {
		if (cache == nullptr) {
			cache = new QStaticText(QString::number(m_lineNumber));
		}

		for (auto * it = m_first; it != nullptr; it = it->next()) {
			it->cacheNow();
		}
	}
	else {
		if (cache != nullptr) {
			delete cache;
			cache = nullptr;

			for (auto * it = m_first; it != nullptr; it = it->next()) {
				it->freeCache();
			}
		}
	}

	m_visible = visible;
	emit visibleChanged(m_visible);
}

void Line::makeChanged() {
	m_parent->makeChanged();
	m_isChanged = true;
}

int Line::charsNumberInLineNumber() {
	return m_charsNumberInLineNumber;
}

}  // namespace icL::editor
