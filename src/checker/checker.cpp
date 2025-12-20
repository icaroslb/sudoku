#include "checker.h"
#include "data/consts.h"

bool Checker::check_line(uint8_t i, uint8_t j, uint8_t value, Board &board){
    for (uint8_t l = 0; l < COLUMN_SIZE; l++) {
        if (board(i, l) == value) {
            return false;
        }
    }

    return true;
}

bool Checker::check_column(uint8_t i, uint8_t j, uint8_t value, Board &board){
    for (uint8_t k = 0; k < LINE_SIZE; k++) {
        if (board(k, j) == value) {
            return false;
        }
    }

    return true;
}

bool Checker::check_box(uint8_t i, uint8_t j, uint8_t value, Board &board){
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

bool Checker::check_pos(uint8_t i, uint8_t j, uint8_t value, Board &board) {
    return check_line(i, j, value, board) && check_column(i, j, value, board) && check_box(i, j, value, board);
}