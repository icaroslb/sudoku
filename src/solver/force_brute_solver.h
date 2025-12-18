#ifndef FORCE_BRUTE_SOLVER_H
#define FORCE_BRUTE_SOLVER_H

#include "solver_interface.h"
#include <memory>
#include <mutex>
#include <cstdint>

class ForceBruteSolver : public SolverInterface {
public:
    ForceBruteSolver(const ForceBruteSolver&) = delete;
    ForceBruteSolver& operator=(const ForceBruteSolver&) = delete;

    /**
     * Get a ForceBruteSolver instance
     * @return ForceBruteSolver instance
     */
    static std::shared_ptr<ForceBruteSolver> get_instance();

    /**
     * Checks the board solvability
     * @param board Board to be checked
     * @return If the board is solvable or not
     */
    Solvability resolve(const Board& board) override;

private:
    ForceBruteSolver() = default;
    static std::weak_ptr<ForceBruteSolver> _instance;
    static std::once_flag init_flag;

    /**
     * Returns the quantity possible numbers the cell (i, j) can have
     * @param i Cell row position
     * @param j Cell column position
     * @param board Board to be checked
     * @return Quantity possible numbers the cell (i, j) can have
     */
    uint8_t unicity(uint8_t i, uint8_t j, Board &board);
};

#endif // FORCE_BRUTE_SOLVER_H