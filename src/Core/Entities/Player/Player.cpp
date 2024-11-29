#include "Player.h"

#include "Actions/AttackAction.h"
#include "Actions/SpellAction.h"

namespace Entities {
    Player::Player(const int health, const int strength) : Character(health, strength) {
        initialize_base_actions();
    }

    Player::~Player() = default;

    void Player::initialize_base_actions() {
        m_player_combat_actions.push_back(std::make_unique<Actions::AttackAction>());
        m_player_combat_actions.push_back(std::make_unique<Actions::SpellAction>());
    }

    const std::vector<std::unique_ptr<Actions::CombatAction> > &Player::get_combat_actions() const {
        return m_player_combat_actions;
    }


    std::vector<std::string> Player::get_available_spells() const {
        return {};
    }
}
