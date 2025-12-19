#ifndef FORCE_BRUTE_SOLVER_H
#define FORCE_BRUTE_SOLVER_H

#include "solver_interface.h"
#include <memory>
#include <mutex>
#include <cstdint>

#include "data/board/board.h"

class ForceBruteSolver {
public:
    ForceBruteSolver() = delete;
    ForceBruteSolver(const ForceBruteSolver&) = delete;
    ForceBruteSolver& operator=(const ForceBruteSolver&) = delete;

    /**
     * Checks the board solvability
     * @param board Board to be checked
     * @return If the board is solvable or not
     */
    static Solvability resolve(const Board& board);

private:
    /**
     * Returns the quantity possible numbers the cell (i, j) can have
     * @param i Cell row position
     * @param j Cell column position
     * @param board Board to be checked
     * @return Quantity possible numbers the cell (i, j) can have
     */
    static uint8_t unicity(uint8_t i, uint8_t j, Board &board);
};

#endif // FORCE_BRUTE_SOLVER_H