#ifndef MASK_GENERATOR_H
#define MASK_GENERATOR_H

#include "data/mask/mask.h"

class MaskGenerator {
public:
    MaskGenerator() = delete;
    MaskGenerator(const MaskGenerator&) = delete;
    MaskGenerator& operator=(const MaskGenerator&) = delete;

    /**
     * Generates a mask with the quantity qtd_hint of hints
     * @param seed Seed used in random number generator
     * @param qtd_hint quantity of hints to generate
     * @return A new mask with the quantity qtd_hint of hints
     */
    static Mask generate(uint seed, uint8_t qtd_hint);
};

#endif // MASK_GENERATOR_H