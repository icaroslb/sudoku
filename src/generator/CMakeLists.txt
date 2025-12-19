set(GENERATOR_INCLUDE ${INCLUDE_PATH}/src/generator)

set(include_file_group
    ${GENERATOR_INCLUDE}/full_board_generator.h
    ${GENERATOR_INCLUDE}/mask_generator.h
)

set(source_file_group
    full_board_generator.cpp
    mask_generator.cpp
)

add_library(generator ${include_file_group} ${source_file_group})
target_include_directories(generator PRIVATE ${GENERATOR_INCLUDE} ${INCLUDE_PATH})
target_link_libraries(generator PRIVATE checker data)