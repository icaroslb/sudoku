#ifndef MASK_GENERATOR_H
#define MASK_GENERATOR_H

#include "data/mask/mask.h"

class MaskGenerator {
    MaskGenerator() = delete;
    MaskGenerator(const MaskGenerator&) = delete;
    MaskGenerator& operator=(const MaskGenerator&) = delete;

    /**
     * Recives a board and return a valid state board full filled
     * @param seed Seed used in random number generator
     * @param board Initial state board
     * @return Valid state board full filled
     */
    static Mask generate(uint seed);

};

#endif // MASK_GENERATOR_H