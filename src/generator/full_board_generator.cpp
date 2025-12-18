#include "full_board_generator.h"
#include <cstdlib>
#include <cmath>

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

    while (qtd_space < WHITE_SPACE) {
        uint8_t line;
        uint8_t column;

        do {
            line = rand() % LINE_SIZE;
            column = rand() % COLUMN_SIZE;
        } while(return_board(line, column) == 0);

        const uint8_t previous_value = return_board(line, column);
        return_board(line, column) = 0;

        if (check_unicity(return_board)) {
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
            if (check_line(i, j, value, board)
             && check_column(i, j, value, board)
             && check_box(i, j, value, board)) {
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

bool FullBoardGenerator::check_line(uint8_t i, uint8_t j, uint8_t value, Board &board){
    for (uint8_t l = 0; l < COLUMN_SIZE; l++) {
        if (board(i, l) == value) {
            return false;
        }
    }

    return true;
}

bool FullBoardGenerator::check_column(uint8_t i, uint8_t j, uint8_t value, Board &board){
    for (uint8_t k = 0; k < LINE_SIZE; k++) {
        if (board(k, j) == value) {
            return false;
        }
    }

    return true;
}

bool FullBoardGenerator::check_box(uint8_t i, uint8_t j, uint8_t value, Board &board){
    const uint8_t begin_line = i - (i % BOX_HEIGHT);
    const uint8_t begin_column = j - (j % BOX_WIDTH);
    const uint8_t end_line = begin_line + BOX_HEIGHT;
    const uint8_t end_column = begin_column + BOX_WIDTH;

    for (uint8_t k = i; k < end_line; k++) {
        for (uint8_t l = j; l < end_column; l++) {
            if (board(k, l) == value) {
                return false;
            }
        }
    }

    return true;
}

bool FullBoardGenerator::check_pos(uint8_t i, uint8_t j, uint8_t value, Board &board) {
    return check_line(i, j, value, board) && check_column(i, j, value, board) && check_box(i, j, value, board);
}

uint8_t FullBoardGenerator::unicity(uint8_t i, uint8_t j, Board &board) {
    if (i == 9) {
        return 0ul;
    }

    const uint8_t l = (j + 1ul) % 9ul;
    const uint8_t k = i + ((l == 0ul) ? 1ul : 0ul);
    uint8_t qtd_solutions = 0ul;

    if (board(i, j) == 0) {
        for (uint8_t value = FIRST_NUM; value < LAST_NUM; value++) {
            if (check_line(i, j, value, board)
             && check_column(i, j, value, board)
             && check_box(i, j, value, board)) {
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

bool FullBoardGenerator::check_unicity(Board &board) {
    const uint8_t qtd_spaces = board.count_white_spaces();

    return qtd_spaces == unicity(FIRST_LINE, FIRST_COLUMN, board);
}