#ifndef CONSTS_H
#define CONSTS_H

#include <cstdint>

// Data informations
const uint8_t COLUMN_SIZE         = 9u;
const uint8_t LINE_SIZE           = 9u;
const uint8_t BOX_WIDTH           = 3u;
const uint8_t BOX_HEIGHT          = 3u;
const uint8_t BOARD_SIZE          = 81u;
const uint8_t MIDDLE_BOARD_LINE   = COLUMN_SIZE / 2u;
const uint8_t MIDDLE_BOARD_COLUMN = 0u;

// Data positions
const uint8_t FIRST_LINE        = 0u;
const uint8_t FIRST_COLUMN      = 0u;
const uint8_t FIRST_BOX_LINE    = 0u;
const uint8_t FIRST_BOX_COLUMN  = 0u;
const uint8_t SECOND_BOX_LINE   = 3u;
const uint8_t SECOND_BOX_COLUMN = 3u;
const uint8_t THIRD_BOX_LINE    = 6u;
const uint8_t THIRD_BOX_COLUMN  = 6u;


// Values informations
const uint8_t EMPTY_VALUE = 0u;
const uint8_t QTD_NUMBER  = 9u;
const uint8_t FIRST_NUM   = 1u;
const uint8_t LAST_NUM    = 10u;

// Annotations informations
const uint16_t NUM_0    = 0b0000000000000000;
const uint16_t NUM_1    = 0b0000000000000010;
const uint16_t NUM_2    = 0b0000000000000100;
const uint16_t NUM_3    = 0b0000000000001000;
const uint16_t NUM_4    = 0b0000000000010000;
const uint16_t NUM_5    = 0b0000000000100000;
const uint16_t NUM_6    = 0b0000000001000000;
const uint16_t NUM_7    = 0b0000000010000000;
const uint16_t NUM_8    = 0b0000000100000000;
const uint16_t NUM_9    = 0b0000001000000000;
const uint16_t ALL_NUMS = 0b0000001111111111;

#endif // CONSTS_H