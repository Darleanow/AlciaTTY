add_library(Core INTERFACE)

add_subdirectory(Entities)
add_subdirectory(Systems)

target_link_libraries(Core INTERFACE Entities Systems)
