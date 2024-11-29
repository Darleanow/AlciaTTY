#include "AttackAction.h"

namespace Actions {
    AttackAction::AttackAction() = default;

    AttackAction::~AttackAction() = default;

    std::string AttackAction::get_name() const {
        return "Perform a basic attack.";
    }

    void AttackAction::execute(Entities::Character *user, Entities::Character *target) {
        const int strength = user->get_strength();

        target->offset_health(-strength);
    }
}
