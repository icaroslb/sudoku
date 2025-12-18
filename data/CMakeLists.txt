set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(board)
add_subdirectory(mask)

add_library(data INTERFACE)
target_link_libraries(data INTERFACE board)
target_include_directories(data INTERFACE ${INCLUDE_PATH})