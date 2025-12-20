set(INCLUDE_MASK ${INCLUDE_PATH}/data/mask)

set(include_file_group
    ${INCLUDE_MASK}/mask.h
    ${INCLUDE_MASK}/hint.h
)

set(source_file_group
    mask.cpp
    hint.cpp
)

add_library(mask ${include_file_group} ${source_file_group})
target_include_directories(mask PRIVATE ${INCLUDE_MASK} ${INCLUDE_PATH})
