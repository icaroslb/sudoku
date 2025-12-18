#include "full_board_generator.h"
#include <cstdlib>
#include <cmath>

#include "../checker/checker.h"
#include "../solver/force_brute_solver.h"

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

std::weak_ptr<FullBoardGenerator> FullBoardGenerator::_instance;
std::once_flag FullBoardGenerator::init_flag;

std::shared_ptr<FullBoardGenerator> FullBoardGenerator::get_instance() {
    std::shared_ptr<FullBoardGenerator> shared_instance = _instance.lock();
    
    if (!shared_instance) {
        std::call_once(init_flag, [&]() {
            shared_instance = std::shared_ptr<FullBoardGenerator>{new FullBoardGenerator{}};
        });
    }
    
    return shared_instance;
}

Board FullBoardGenerator::generate(uint seed, const Board& board) {
    srand(seed);
    Board return_board = board;

    generate_3x3(FIRST_BOX_LINE, FIRST_BOX_COLUMN, return_board);
    generate_3x3(SECOND_BOX_LINE, SECOND_BOX_COLUMN, return_board);
    generate_3x3(THIRD_BOX_LINE, THIRD_BOX_COLUMN, return_board);
    generate_9x9(FIRST_LINE, FIRST_COLUMN, return_board);

    uint8_t qtd_space = 0ul;

    std::shared_ptr<SolverInterface> solver = ForceBruteSolver::get_instance();

    while (qtd_space < WHITE_SPACE) {
        uint8_t line;
        uint8_t column;

        do {
            line = rand() % LINE_SIZE;
            column = rand() % COLUMN_SIZE;
        } while(return_board(line, column) == 0);

        const uint8_t previous_value = return_board(line, column);
        return_board(line, column) = 0;

        if (solver->resolve(return_board) == Solvability::SOLVABLE) {
            qtd_space += 1ul;
        } else {
            return_board(line, column) = previous_value;
        }
    }

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
            board(k, l) = new_number + 1;
        }
    }
}

bool FullBoardGenerator::generate_9x9(uint8_t i, uint8_t j, Board &board) {
    if (i == 9) {
        return true;
    }

    const uint8_t l = (j + 1ul) % 9ul;
    const uint8_t k = i + ((l == 0ul) ? 1ul : 0ul);

    if (board(i, j) == 0) {
        for (uint8_t value = FIRST_NUM; value < LAST_NUM; value++) {
            if (Checker::check_line(i, j, value, board)
             && Checker::check_column(i, j, value, board)
             && Checker::check_box(i, j, value, board)) {
                board(i, j) = value;

                if (generate_9x9(k, l, board)) {
                    return true;
                } else {
                    board(i, j) = 0;
                }
            }
        }

        return false;
    } else {
        return generate_9x9(k, l, board);
    }
}