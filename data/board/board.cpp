#include "board.h"
#include "data/consts.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

Board::Board() : _board(BOARD_SIZE, EMPTY_VALUE) {}

Board::Board(const Board& board) : _board(board._board.size()) {
    std::copy(std::begin(board._board), std::end(board._board), std::begin(_board));
}

Board& Board::operator=(const Board& board) {
    if (this != &board) {
        _board.resize(board._board.size());
        std::copy(std::begin(board._board), std::end(board._board), std::begin(_board));
    }

    return *this;
}

const uint8_t& Board::operator()(uint8_t i, uint8_t j) const {
    return _board[(i * COLUMN_SIZE) + j];
}

uint8_t& Board::operator()(uint8_t i, uint8_t j) {
    return _board[(i * COLUMN_SIZE) + j];
}

Board Board::apply_mask(const Mask& mask) const {
    Board board_masked{};
    
    std::for_each(std::begin(mask), std::end(mask), [&](const Hint& hint){
        board_masked(hint.line(), hint.column()) = this->operator()(hint.line(), hint.column());
    });

    return board_masked;
}

uint8_t Board::count_white_spaces() const {
    return std::count_if(std::begin(_board), std::end(_board), [](const uint8_t &value) {
        return value == 0u;
    });
}

std::ostream& operator<< (std::ostream& os, const Board& b) {
    for (uint8_t i = 0; i < LINE_SIZE; i++) {
        for (uint8_t j = 0; j < COLUMN_SIZE; j++) {
            os << (uint)b(i, j) << ' ';
        }

        os << std::endl;
    }

    return os;
}