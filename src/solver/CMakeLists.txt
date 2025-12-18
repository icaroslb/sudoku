add_library(solver solver_interface.h force_brute_solver.h force_brute_solver.cpp)
target_link_libraries(solver checker board)