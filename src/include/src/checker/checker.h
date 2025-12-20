#ifndef CHECKER_H
#define CHECKER_H

#include "data/board/board.h"

#include <cstdint>

class Checker {
public:
    /**
     * Checks if is valid to insert the value in (i, j) cell analyzing the row
     * @param i Cell row position
     * @param j Cell column position
     * @param value Value to be checked
     * @param board Board to be checked
     * @return true if value is valid, false otherwise
     */
    static bool check_line(uint8_t i, uint8_t j, uint8_t value, Board &board);

    /**
     * Checks if is valid to insert the value in (i, j) cell analyzing the column
     * @param i Cell row position
     * @param j Cell column position
     * @param value Value to be checked
     * @param board Board to be checked
     * @return true if value is valid, false otherwise
     */
    static bool check_column(uint8_t i, uint8_t j, uint8_t value, Board &board);

    /**
     * Checks if is valid to insert the value in (i, j) cell analyzing the box
     * @param i Cell row position
     * @param j Cell column position
     * @param value Value to be checked
     * @param board Board to be checked
     * @return true if value is valid, false otherwise
     */
    static bool check_box(uint8_t i, uint8_t j, uint8_t value, Board &board);

    /**
     * Checks if is valid to insert the value in (i, j) cell analyzing the board
     * @param i Cell row position
     * @param j Cell column position
     * @param value Value to be checked
     * @param board Board to be checked
     * @return True if value is valid, false otherwise
     */
    static bool check_pos(uint8_t i, uint8_t j, uint8_t value, Board &board);
};

#endif // CHECKER_H