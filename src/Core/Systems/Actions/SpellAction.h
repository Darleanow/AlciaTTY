#pragma once
#include "CombatAction.h"

namespace Actions {
    class SpellAction final : public CombatAction {
    public:
        SpellAction();

        ~SpellAction() override;

        [[nodiscard]] std::string get_name() const override;

        void execute(Entities::Character *user, Entities::Character *target) override;
    };
}
