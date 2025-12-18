#ifndef RESOLVER_H
#define RESOLVER_H

#include "../board/board.h"

enum class Solvability {
    NO_SOLVABLE,
    SOLVABLE,
    SUPER_EASY,
    VERY_EASY,
    EASY,
    MEDIUM,
    HARD,
    HARDER,
    VERY_HARD,
    SUPER_HARD
};

class SolverInterface {
public:
    /**
     * Checks the board solvability
     * @param board Board to be checked
     * @return The solvability of the board
     */
    virtual Solvability resolve(const Board& board) = 0;
};

#endif // RESOLVER_H