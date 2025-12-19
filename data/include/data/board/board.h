#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstdint>
#include <ostream>

#include "data/mask/mask.h"

class Board {
public:
    Board();
    Board(const Board& board);

    Board& operator=(const Board& board);

    const uint8_t& operator()(uint8_t i, uint8_t j) const;
    uint8_t& operator()(uint8_t i, uint8_t j);

    /**
     * Generates a board with mask applied
     * @param mask Mask to be applied
     * @return Board with mask applied
     */
    Board apply_mask(const Mask& mask);

    /**
     * Returns the quantity of white spaces
     * @return The sum of white spaces
     */
    uint8_t count_white_spaces() const;

    friend std::ostream& operator<< (std::ostream& os, const Board& b);

private:
    std::vector<uint8_t> _board;
};

std::ostream& operator<< (std::ostream& os, const Board& b);

#endif // BOARD_H