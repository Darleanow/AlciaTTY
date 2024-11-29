#include "Character.h"

namespace Entities {
    Character::Character(const int health, const int strength) : m_health(health), m_max_health(health),
                                                                 m_strength(strength) {
    }

    Character::~Character() = default;

    [[nodiscard]] int Character::get_strength() const {
        return m_strength;
    }

    void Character::offset_strength(const int delta) {
        m_strength += delta;
    }

    [[nodiscard]] int Character::get_health() const {
        return m_health;
    }

    int Character::get_max_health() const {
        return m_max_health;
    }


    void Character::offset_health(const int delta) {
        m_health += delta;
    }

    [[nodiscard]] bool Character::is_alive() const {
        return m_health > 0;
    }
}
