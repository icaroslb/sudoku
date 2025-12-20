#include "full_board_generator.h"
#include "data/consts.h"
#include "src/checker/checker.h"
#include "src/solver/force_brute_solver.h"


Board FullBoardGenerator::generate(uint seed) {
    srand(seed);
    Board return_board{};

    generate_3x3(FIRST_BOX_LINE, FIRST_BOX_COLUMN, return_board);
    generate_3x3(SECOND_BOX_LINE, SECOND_BOX_COLUMN, return_board);
    generate_3x3(THIRD_BOX_LINE, THIRD_BOX_COLUMN, return_board);
    generate_9x9(FIRST_LINE, FIRST_COLUMN, return_board);

    return return_board;
}

void FullBoardGenerator::generate_3x3(uint8_t i, uint8_t j, Board &board) {
    uint16_t number_mask = 0u;
    uint16_t mask = 0b1;

    for (uint8_t k = i; k < i + BOX_WIDTH; k++) {
        for (uint8_t l = j; l < j + BOX_HEIGHT; l++) {
            uint8_t new_number = rand() % QTD_NUMBER;

            while(number_mask & (mask << new_number)) {
                new_number = (new_number + 1) % QTD_NUMBER;
            }

            number_mask = number_mask | (mask << new_number);
            board(k, l) = new_number + 1u;
        }
    }
}

bool FullBoardGenerator::generate_9x9(uint8_t i, uint8_t j, Board &board) {
    if (i == COLUMN_SIZE) {
        return true;
    }

    // Get next column and line position
    const uint8_t l = (j + 1u) % LINE_SIZE;
    const uint8_t k = i + ((l == 0) ? 1u : 0u);

    if (board(i, j) == 0) {
        for (uint8_t value = FIRST_NUM; value < LAST_NUM; value++) {
            if (Checker::check_line(i, j, value, board)
             && Checker::check_column(i, j, value, board)
             && Checker::check_box(i, j, value, board)) {
                board(i, j) = value;

                if (generate_9x9(k, l, board)) {
                    return true;
                } else {
                    board(i, j) = 0u;
                }
            }
        }

        return false;
    } else {
        return generate_9x9(k, l, board);
    }
}