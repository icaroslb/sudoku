#include <iostream>
#include <memory>
#include "data/board/board.h"
#include "src/generator/full_board_generator.h"

int main() {
    Board board{};
    board = FullBoardGenerator::generate(3, board);

    std::cout << board <<std::endl;

    return 0;
}