set(GENERATOR_INCLUDE ${INCLUDE_PATH}/src/generator)


add_library(generator ${GENERATOR_INCLUDE}/full_board_generator.h full_board_generator.cpp)
target_include_directories(generator PRIVATE ${GENERATOR_INCLUDE} ${INCLUDE_PATH})
target_link_libraries(generator PRIVATE checker data)