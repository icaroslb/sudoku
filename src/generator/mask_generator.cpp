#include "mask_generator.h"
#include "data/consts.h"

#include <random>

Mask MaskGenerator::generate(uint seed, uint8_t qtd_hint) {
    Mask new_mask{};
    uint8_t count = 0u;
    std::default_random_engine re{seed};
    srand(seed);

    while (count < qtd_hint) {
        const uint8_t x = rand() % LINE_SIZE;
        const uint8_t y = rand() % COLUMN_SIZE;

        if (new_mask(x, y) == MaskValue::EMPTY) {
            new_mask(x, y) = MaskValue::FILL;
            count++;
        }
    }

    return new_mask;
}