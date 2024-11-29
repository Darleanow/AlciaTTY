add_library(Systems
        Combat/Combat.cpp
        Actions/CombatAction.cpp
        Actions/AttackAction.cpp
        Actions/SpellAction.cpp
)

target_link_libraries(Systems PRIVATE Entities UI)

target_include_directories(Systems PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
