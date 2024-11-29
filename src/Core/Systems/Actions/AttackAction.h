#pragma once
#include "Actions/CombatAction.h"

namespace Actions {
    class AttackAction final : public CombatAction {
    public:
        AttackAction();
        ~AttackAction() override;

        [[nodiscard]] std::string get_name() const override;

        void execute(Entities::Character *user, Entities::Character *target) override;
    };
}