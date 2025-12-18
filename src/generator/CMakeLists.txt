set(GENERATOR_INCLUDE ${INCLUDE_PATH}/src/generator)


add_library(generator ${GENERATOR_INCLUDE}/generator_interface.h ${GENERATOR_INCLUDE}/full_board_generator.h full_board_generator.cpp)
target_include_directories(generator PRIVATE ${GENERATOR_INCLUDE})
target_link_libraries(generator PRIVATE checker data)