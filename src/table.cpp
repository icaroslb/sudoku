#include "table.h"
#include <cstdlib>
#include <cmath>

const size_t COLUMN_SIZE = 9ul;
const size_t LINE_SIZE = 9ul;
const size_t QTD_NUMBER = 9ul;
const size_t BOX_WIDTH = 3ul;
const size_t BOX_HEIGHT = 3ul;

const size_t FIRST_LINE = 0ul;
const size_t FIRST_COLUMN = 0ul;
const size_t FIRST_BOX_LINE = 0ul;
const size_t FIRST_BOX_COLUMN = 0ul;
const size_t SECOND_BOX_LINE = 3ul;
const size_t SECOND_BOX_COLUMN = 3ul;
const size_t THIRD_BOX_LINE = 6ul;
const size_t THIRD_BOX_COLUMN = 6ul;

const uint8_t FIRST_NUM = 1u;
const uint8_t LAST_NUM = 10u;

Table::Table(size_t seed) : _table(81u, 0u) {
    
    srand(seed);
    generate_3x3(FIRST_BOX_LINE, FIRST_BOX_COLUMN);
    generate_3x3(SECOND_BOX_LINE, SECOND_BOX_COLUMN);
    generate_3x3(THIRD_BOX_LINE, THIRD_BOX_COLUMN);
    generate_9x9(FIRST_LINE, FIRST_COLUMN);
}

uint8_t Table::operator()(size_t i, size_t j) const {
    return _table[(i * COLUMN_SIZE) + j];
}

uint8_t& Table::operator()(size_t i, size_t j) {
    return _table[(i * COLUMN_SIZE) + j];
}

void Table::generate_3x3(size_t i, size_t j) {
    uint16_t number_mask = 0u;
    uint16_t mask = 0b1;

    for (size_t k = i; k < i + BOX_WIDTH; k++) {
        for (size_t l = j; l < j + BOX_HEIGHT; l++) {
            uint8_t new_number = rand() % QTD_NUMBER;

            while(number_mask & (mask << new_number)) {
                new_number = (new_number + 1) % QTD_NUMBER;
            }

            number_mask = number_mask | (mask << new_number);
            this->operator()(k, l) = new_number + 1;
        }
    }
}

bool Table::generate_9x9(size_t i, size_t j) {
    if (i == 9) {
        return true;
    }

    const size_t l = (j + 1ul) % 9ul;
    const size_t k = i + ((l == 0ul) ? 1ul : 0ul);

    if (this->operator()(i, j) == 0) {
        for (uint8_t value = FIRST_NUM; value < LAST_NUM; value++) {
            if (check_line(i, j, value)
             && check_column(i, j, value)
             && check_box(i, j, value)) {
                this->operator()(i, j) = value;

                if (generate_9x9(k, l)) {
                    return true;
                } else {
                    this->operator()(i, j) = 0;
                }
            }
        }

        return false;
    } else {
        return generate_9x9(k, l);
    }
}

bool Table::check_line(size_t i, size_t j, uint8_t value){
    for (size_t l = 0; l < COLUMN_SIZE; l++) {
        if (this->operator()(i, l) == value) {
            return false;
        }
    }

    return true;
}

bool Table::check_column(size_t i, size_t j, uint8_t value){
    for (size_t k = 0; k < LINE_SIZE; k++) {
        if (this->operator()(k, j) == value) {
            return false;
        }
    }

    return true;
}

bool Table::check_box(size_t i, size_t j, uint8_t value){
    const size_t begin_line = i - (i % BOX_HEIGHT);
    const size_t begin_column = j - (j % BOX_WIDTH);
    const size_t end_line = begin_line + BOX_HEIGHT;
    const size_t end_column = j + BOX_WIDTH;

    for (size_t k = i; k < end_line; k++) {
        for (size_t l = j; l < end_column; l++) {
            if (this->operator()(k, l) == value) {
                return false;
            }
        }
    }

    return true;
}

bool Table::check_pos(size_t i, size_t j, uint8_t value) {
    return check_line(i, j, value) && check_column(i, j, value) && check_box(i, j, value);
}

std::ostream& operator<< (std::ostream& os, const Table& t) {
    for (size_t i = 0; i < LINE_SIZE; i++) {
        for (size_t j = 0; j < COLUMN_SIZE; j++) {
            os << (uint)t(i, j) << ' ';
        }

        os << std::endl;
    }

    return os;
}