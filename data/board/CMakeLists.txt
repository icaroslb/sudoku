set(INCLUDE_BOARD ${INCLUDE_PATH}/data/board)

add_library(board ${INCLUDE_BOARD}/board.h board.cpp)
target_include_directories(board PRIVATE ${INCLUDE_BOARD})
