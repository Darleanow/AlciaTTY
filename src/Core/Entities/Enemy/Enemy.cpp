#include "Enemy.h"

namespace Entities {
    Enemy::Enemy(const int health, const int strength) : Character(health, strength) {
    }

    Enemy::~Enemy() = default;

    std::vector<std::string> Enemy::get_available_spells() const {
        return {};
    }

    void Enemy::execute_action(Player &target) const {
        // For now, only base attacks
        target.offset_health(-get_strength());
    }
}
