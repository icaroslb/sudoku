#include <vector>
#include <cstdint>
#include <ostream>

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    Board(const Board& board);

    Board& operator=(const Board& board);

    uint8_t operator()(size_t i, size_t j) const;
    uint8_t& operator()(size_t i, size_t j);

    /**
     * Returns the quantity of white spaces
     * @return The sum of white spaces
     */
    size_t count_white_spaces() const;

    friend std::ostream& operator<< (std::ostream& os, const Board& t);

private:
    std::vector<uint8_t> _board;
};

std::ostream& operator<< (std::ostream& os, const Board& t);

#endif // BOARD_H