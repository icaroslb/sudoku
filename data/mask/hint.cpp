#include "hint.h"

Hint::Hint(uint8_t new_line, uint8_t new_column)
: _line(new_line)
, _column(new_column)
{}

uint8_t& Hint::line() {
    return _line;
}

const uint8_t& Hint::line() const {
    return _line;
}

uint8_t& Hint::column() {
    return _column;
}
const uint8_t& Hint::column() const {
    return _column;
}

bool Hint::operator<(const Hint& hint) const {
    return (_line < hint._line) || (_line == hint._line && _column < hint._column);
}