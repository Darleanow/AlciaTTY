#pragma once
#include <vector>
#include <string>

namespace Entities {
    class Character {
    public:
        Character(int health, int strength);

        virtual ~Character() = 0;

        [[nodiscard]] int get_strength() const;

        void offset_strength(int delta);

        [[nodiscard]] int get_health() const;

        [[nodiscard]] int get_max_health() const;

        void offset_health(int delta);

        [[nodiscard]] bool is_alive() const;

        virtual [[nodiscard]] std::vector<std::string> get_available_spells() const = 0;

    private:
        int m_health;
        int m_max_health;

        int m_strength;
    };
}
