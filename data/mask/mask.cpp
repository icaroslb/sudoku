#include "mask.h"
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>

const uint8_t COLUMN_SIZE = 9ul;
const uint8_t LINE_SIZE = 9ul;

Mask::Mask() : _mask(81u, MaskValue::EMPTY) {}

Mask::Mask(const Mask& mask) : _mask(mask._mask.size()) {
    std::copy(std::begin(mask._mask), std::end(mask._mask), std::begin(_mask));
}

Mask& Mask::operator=(const Mask& mask) {
    if (this != &mask) {
        _mask.resize(mask._mask.size());
        std::copy(std::begin(mask._mask), std::end(mask._mask), std::begin(_mask));
    }

    return *this;
}

const MaskValue& Mask::operator()(uint8_t i, uint8_t j) const {
    return _mask[(i * COLUMN_SIZE) + j];
}

MaskValue& Mask::operator()(uint8_t i, uint8_t j) {
    return _mask[(i * COLUMN_SIZE) + j];
}

uint8_t Mask::count_white_spaces() const {
    return std::count_if(std::begin(_mask), std::end(_mask), [](const MaskValue &value) {
        return value == MaskValue::EMPTY;
    });
}

std::ostream& operator<< (std::ostream& os, const Mask& b) {
    for (uint8_t i = 0; i < LINE_SIZE; i++) {
        for (uint8_t j = 0; j < COLUMN_SIZE; j++) {
            os << (uint)b(i, j) << ' ';
        }

        os << std::endl;
    }

    return os;
}