#ifndef MASK_H
#define MASK_H

#include <vector>
#include <cstdint>
#include <ostream>

enum class MaskValue {
    FILL,
    EMPTY
};

class Mask {
public:
    Mask();
    Mask(const Mask& mask);

    Mask& operator=(const Mask& mask);

    const MaskValue& operator()(uint8_t i, uint8_t j) const;
    MaskValue& operator()(uint8_t i, uint8_t j);

    /**
     * Returns the quantity of white spaces
     * @return The sum of white spaces
     */
    uint8_t count_white_spaces() const;

    friend std::ostream& operator<< (std::ostream& os, const Mask& m);
    friend class Board;

private:
    std::vector<MaskValue> _mask;
};

std::ostream& operator<< (std::ostream& os, const Mask& m);

#endif // MASK_H