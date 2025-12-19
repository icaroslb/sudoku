set(SOLVER_INCLUDE ${INCLUDE_PATH}/src/solver)

set(include_file_group
    ${SOLVER_INCLUDE}/force_brute_solver.h
)

set(source_file_group
    force_brute_solver.cpp
)

add_library(solver ${include_file_group} ${source_file_group})
target_include_directories(solver PRIVATE ${SOLVER_INCLUDE} ${INCLUDE_PATH})
target_link_libraries(solver PRIVATE checker data)