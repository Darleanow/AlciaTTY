cmake_minimum_required(VERSION 3.28)
project(AlciaTTY)

set(CMAKE_CXX_STANDARD 26)

add_executable(AlciaTTY main.cpp)

add_subdirectory(src)

target_link_libraries(AlciaTTY PRIVATE UI) # Libs here

add_compile_options(
        -Wall        # Enable all warnings
        -Wextra      # Additional warnings
        -Wpedantic   # Strict ISO compliance
        -Werror      # Treat warnings as errors
)

set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Od")          # debugging flags
set(CMAKE_CXX_FLAGS_RELEASE "/O2")            # high optimization
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/O2 /Zi") # optimized with debug info

add_custom_command(
        TARGET AlciaTTY POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/Data/Location.json
        $<TARGET_FILE_DIR:AlciaTTY>/Data/Location.json
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/Data/Enemies.json
        $<TARGET_FILE_DIR:AlciaTTY>/Data/Enemies.json
)