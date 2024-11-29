add_library(UI
        Components/MultiOptionInput.cpp
)

target_include_directories(UI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)