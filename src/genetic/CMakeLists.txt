set(GENETIC_INCLUDE ${INCLUDE_PATH}/src/genetic)

set(include_file_group
    ${GENETIC_INCLUDE}/genetic.h
)

set(source_file_group
    genetic.cpp
)

add_library(genetic ${include_file_group} ${source_file_group})
target_include_directories(genetic PRIVATE ${GENETIC_INCLUDE} ${INCLUDE_PATH})
target_link_libraries(genetic PRIVATE data)