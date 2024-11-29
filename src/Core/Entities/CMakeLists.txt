add_library(Entities
        Enemy/Enemy.cpp
)
target_link_libraries(Entities PRIVATE Systems)

target_include_directories(Entities PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)