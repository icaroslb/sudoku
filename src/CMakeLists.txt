add_subdirectory(board)
add_subdirectory(checker)
add_subdirectory(generator)
add_subdirectory(solver)

add_library(src INTERFACE)
target_link_libraries(src INTERFACE board checker generator solver)