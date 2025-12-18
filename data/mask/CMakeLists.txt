set(INCLUDE_MASK ${INCLUDE_PATH}/data/mask)

add_library(mask ${INCLUDE_MASK}/mask.h mask.cpp)
target_include_directories(mask PRIVATE ${INCLUDE_MASK})
