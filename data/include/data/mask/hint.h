#ifndef HINT_H
#define HINT_H

#include <cstdint>

class Hint {
public:
    Hint(uint8_t new_line, uint8_t new_column);

    uint8_t& line();
    const uint8_t& line() const;

    uint8_t& column();
    const uint8_t& column() const;

    bool operator<(const Hint& hint) const;

private:
    uint8_t _line;
    uint8_t _column;
};

#endif // HINT_H