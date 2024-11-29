#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Character/Character.h"
#include "Actions/CombatAction.h"


namespace Entities {
    class Player final : public Character {
    public:
        Player(int health, int strength);

        ~Player() override;

        void initialize_base_actions();

        [[nodiscard]] const std::vector<std::unique_ptr<Actions::CombatAction> > &get_combat_actions() const;

        [[nodiscard]] std::vector<std::string> get_available_spells() const override;

    private:
        std::vector<std::unique_ptr<Actions::CombatAction> > m_player_combat_actions;
        // TODO: Systems (xp, inventory, abilities)
    };
}
