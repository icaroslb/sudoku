set(INCLUDE_BOARD ${INCLUDE_PATH}/data/board)

set(include_file_group
    ${INCLUDE_BOARD}/board.h
)

set(source_file_group
    board.cpp
)

add_library(board ${include_file_group} ${source_file_group})
target_link_libraries(board mask)
target_include_directories(board PRIVATE ${INCLUDE_BOARD} ${INCLUDE_PATH})
