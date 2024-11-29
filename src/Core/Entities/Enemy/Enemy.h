#pragma once
#include "Character/Character.h"
#include "Player/Player.h"

namespace Entities {
    class Enemy final : public Character {
    public:
        Enemy(int health, int strength);

        ~Enemy() override;

        [[nodiscard]] std::vector<std::string> get_available_spells() const override;

        void execute_action(Player &target) const;

    private:
        // TODO: Systems (abilities)
    };
}
