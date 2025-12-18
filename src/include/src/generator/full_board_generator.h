#ifndef FULL_BOARD_GENERATOR_H
#define FULL_BOARD_GENERATOR_H

#include <memory>
#include <mutex>
#include <cstdint>

#include "generator_interface.h"

class FullBoardGenerator : public GeneratorInterface{
public:
    FullBoardGenerator(const FullBoardGenerator&) = delete;
    FullBoardGenerator& operator=(const FullBoardGenerator&) = delete;

    /**
     * Get a FullBoardGenerator instance
     * @return FullBoardGenerator instance
     */
    static std::shared_ptr<FullBoardGenerator> get_instance();

    /**
     * Recives a board and return a valid state board full filled
     * @param seed Seed used in random number generator
     * @param board Initial state board
     * @return Valid state board full filled
     */
    Board generate(uint seed, const Board& board) override;

private:
    FullBoardGenerator() = default;
    static std::weak_ptr<FullBoardGenerator> _instance;
    static std::once_flag init_flag;

    /**
     * Generates a 3x3 valid box where cell (i, j) belongs
     * @param i Cell row possition
     * @param j Cell column position
     * @param board Board to be inserted the generated 3x3 box
     * @return void
     */
    void generate_3x3(uint8_t i, uint8_t j, Board &board);

    /**
     * Generates a 9x9 valid board initializing by cell (i, j)
     * @param i Initial row position
     * @param j Initial column position
     * @param board Board to be inserted the generated 9x9 board
     */
    bool generate_9x9(uint8_t i, uint8_t j, Board &board);
};

#endif // FULL_BOARD_GENERATOR_H