set(CHECKER_INCLUDE ${INCLUDE_PATH}/src/checker)

set(include_file_group
    ${CHECKER_INCLUDE}/checker.h
)

set(source_file_group
    checker.cpp
)

add_library(checker ${include_file_group} ${source_file_group})

target_include_directories(checker PRIVATE ${CHECKER_INCLUDE} ${INCLUDE_PATH})
target_link_libraries(checker PRIVATE data)