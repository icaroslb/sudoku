#ifndef GENERATOR_INTERFACE_H
#define GENERATOR_INTERFACE_H

#include "../board/board.h"

class GeneratorInterface {
public:
    /**
     * Recives a board and return a valid state board
     * @param seed Seed used in random number generator
     * @param board Initial state board
     * @return Valid state board
     */
    virtual Board generate(uint seed, const Board& board) = 0;
};

#endif // GENERATOR_INTERFACE_H