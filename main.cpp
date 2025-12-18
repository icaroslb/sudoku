#include <iostream>
#include <memory>
#include "data/board/board.h"
#include "src/generator/full_board_generator.h"

int main() {
    Board board{};
    std::shared_ptr<GeneratorInterface> generator = FullBoardGenerator::get_instance();
    board = generator->generate(3, board);

    std::cout << board <<std::endl;

    return 0;
}