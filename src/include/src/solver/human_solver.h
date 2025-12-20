#ifndef HUMAN_SOLVER_H
#define HUMAN_SOLVER_H

#include "solvability.h"
#include "data/board/board.h"

#include <cstdint>

class HumanSolver {
public:
    HumanSolver() = delete;
    HumanSolver(const HumanSolver&) = delete;
    HumanSolver& operator=(const HumanSolver&) = delete;

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
    static uint8_t last_free_cell(uint8_t i, uint8_t j, Board &board);
};

#endif // HUMAN_SOLVER_H