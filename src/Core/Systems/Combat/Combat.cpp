#include "Combat.h"

#include <ranges>
#include "Components/MultiOptionInput.h"

namespace Systems {
    Combat::Combat(Entities::Player &player, Entities::Enemy &enemy) : m_player(player), m_enemy(enemy) {
    }

    Combat::~Combat() = default;

    void Combat::handle_combat() const {
        while (can_combat_continue()) {
            std::cout << Utils::ClearScreen;

            display_combat_infos();

            std::cout << "\n\n";

            const int result = prompt_player_actions();

            // Player turn
            m_player.get_combat_actions().at(result)->execute(&m_player, &m_enemy);

            // Enemy Turn
            m_enemy.execute_action(m_player);
        }
    }

    void Combat::display_combat_infos() const {
        std::cout << Utils::Font::BrightRed << "[EnemyName]" << "\n";
        std::cout << Utils::Font::Red << "Health: " << m_enemy.get_health() << "/" << m_enemy.get_max_health() << "\n";
        std::cout << Utils::Font::BrightYellow << "Strength: " << m_enemy.get_strength() << "\n";
        std::cout << "\n";
        std::cout << Utils::Font::BrightBlue << "[HeroName]" << "\n";
        std::cout << Utils::Font::Red << "Health: " << m_player.get_health() << "/" << m_player.get_max_health() <<
                "\n";
        std::cout << Utils::Font::BrightYellow << "Strength: " << m_player.get_strength() << "\n";

        std::cout << Utils::Font::Reset;
    }


    int Combat::prompt_player_actions() const {
        const auto action_names = m_player.get_combat_actions()
                                  | std::views::transform([](const auto &action) {
                                      return action->get_name();
                                  });
        const UI::MultiOptionInput options("What would you like to do ?", action_names);

        return options.get_result_index();
    }

    bool Combat::can_combat_continue() const {
        return m_enemy.is_alive() && m_player.is_alive();
    }
}
