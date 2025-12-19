#ifndef GENETIC_H
#define GENETIC_H

#include "data/board/board.h"
#include "data/mask/mask.h"

class Genetic {
public:
    Genetic() = delete;
    Genetic(const Genetic&) = delete;
    Genetic& operator=(const Genetic&) = delete;

    Mask operate(const Board& board);

private:
};

#endif // GENETIC_H