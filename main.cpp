#include <iostream>
#include <memory>
#include "data/board/board.h"
#include "src/generator/full_board_generator.h"

int main() {
    Board board = FullBoardGenerator::generate(3);

    std::cout << board <<std::endl;

    return 0;
}