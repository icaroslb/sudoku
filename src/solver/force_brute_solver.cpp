#include "force_brute_solver.h"
#include "src/checker/checker.h"
#include "data/consts.h"

Solvability ForceBruteSolver::resolve(const Board& board) {
    const uint8_t qtd_spaces = board.count_white_spaces();
    Board check_board = board;
    Solvability solvability = Solvability::NO_SOLVABLE;

    if (unicity(FIRST_LINE, FIRST_COLUMN, check_board)) {
        solvability = Solvability::SOLVABLE;
    }

    return solvability;
}

uint8_t ForceBruteSolver::unicity(uint8_t i, uint8_t j, Board &board) {
    if (i == COLUMN_SIZE) {
        return 0u;
    }

    // Get next column and line position
    const uint8_t l = (j + 1u) % LINE_SIZE;
    const uint8_t k = i + ((l == 0u) ? 1u : 0u);
    uint8_t qtd_solutions = 0u;

    if (board(i, j) == 0) {
        for (uint8_t value = FIRST_NUM; value < LAST_NUM; value++) {
            if (Checker::check_line(i, j, value, board)
             && Checker::check_column(i, j, value, board)
             && Checker::check_box(i, j, value, board)) {
                board(i, j) = value;

                const uint8_t qtd_sub_solutions = unicity(k, l, board);

                qtd_solutions += qtd_sub_solutions + 1u;
            }

            board(i, j) = 0;
        }
    } else {
        qtd_solutions = unicity(k, l, board);
    }

    return qtd_solutions;
}