set(CHECKER_INCLUDE ${INCLUDE_PATH}/src/checker)

add_library(checker ${CHECKER_INCLUDE}/checker.h checker.cpp)

target_include_directories(checker PRIVATE ${CHECKER_INCLUDE})
target_link_libraries(checker PRIVATE data)