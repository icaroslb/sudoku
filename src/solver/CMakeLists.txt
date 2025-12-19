set(SOLVER_INCLUDE ${INCLUDE_PATH}/src/solver)

add_library(solver ${SOLVER_INCLUDE}/force_brute_solver.h force_brute_solver.cpp)
target_include_directories(solver PRIVATE ${SOLVER_INCLUDE} ${INCLUDE_PATH})
target_link_libraries(solver PRIVATE checker data)