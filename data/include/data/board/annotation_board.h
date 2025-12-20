#ifndef ANNOTATION_BOARD_H
#define ANNOTATION_BOARD_H

#include <vector>
#include <cstdint>

class AnnotationBoard {
public:
    AnnotationBoard();
    AnnotationBoard(const AnnotationBoard& board);

    AnnotationBoard& operator=(const AnnotationBoard& board);

    const uint8_t& operator()(uint8_t i, uint8_t j) const;
    uint8_t& operator()(uint8_t i, uint8_t j);

private:
    std::vector<uint16_t> _board;
};

#endif // ANNOTATION_BOARD_H