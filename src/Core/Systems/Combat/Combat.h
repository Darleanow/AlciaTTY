#pragma once
#include "Player/Player.h"
#include "Enemy/Enemy.h"

namespace Systems {
    class Combat {
    public:
        Combat(Entities::Player &player, Entities::Enemy &enemy);

        ~Combat();

        void handle_combat() const;

    private:
        void display_combat_infos() const;

        [[nodiscard]] int prompt_player_actions() const;

        [[nodiscard]] bool can_combat_continue() const;

        Entities::Player &m_player;
        Entities::Enemy &m_enemy;
    };
}
