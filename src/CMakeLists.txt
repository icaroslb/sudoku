set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(checker)
add_subdirectory(generator)
add_subdirectory(solver)

add_library(src INTERFACE)
target_include_directories(src INTERFACE ${INCLUDE_PATH})
target_link_libraries(src INTERFACE checker generator solver)