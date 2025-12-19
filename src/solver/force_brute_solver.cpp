#include "force_brute_solver.h"

#include "../checker/checker.h"

const uint8_t COLUMN_SIZE = 9ul;
const uint8_t LINE_SIZE = 9ul;
const uint8_t QTD_NUMBER = 9ul;
const uint8_t BOX_WIDTH = 3ul;
const uint8_t BOX_HEIGHT = 3ul;

const uint8_t FIRST_LINE = 0ul;
const uint8_t FIRST_COLUMN = 0ul;
const uint8_t FIRST_BOX_LINE = 0ul;
const uint8_t FIRST_BOX_COLUMN = 0ul;
const uint8_t SECOND_BOX_LINE = 3ul;
const uint8_t SECOND_BOX_COLUMN = 3ul;
const uint8_t THIRD_BOX_LINE = 6ul;
const uint8_t THIRD_BOX_COLUMN = 6ul;

const uint8_t FIRST_NUM = 1u;
const uint8_t LAST_NUM = 10u;

const uint8_t WHITE_SPACE = 20ul;

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
    if (i == 9) {
        return 0ul;
    }

    const uint8_t l = (j + 1ul) % 9ul;
    const uint8_t k = i + ((l == 0ul) ? 1ul : 0ul);
    uint8_t qtd_solutions = 0ul;

    if (board(i, j) == 0) {
        for (uint8_t value = FIRST_NUM; value < LAST_NUM; value++) {
            if (Checker::check_line(i, j, value, board)
             && Checker::check_column(i, j, value, board)
             && Checker::check_box(i, j, value, board)) {
                board(i, j) = value;

                const uint8_t qtd_sub_solutions = unicity(k, l, board);

                qtd_solutions += qtd_sub_solutions + 1ul;
            }

            board(i, j) = 0;
        }
    } else {
        qtd_solutions = unicity(k, l, board);
    }

    return qtd_solutions;
}