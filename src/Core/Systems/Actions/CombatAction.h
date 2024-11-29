#pragma once
#include <string>
#include <Character/Character.h>

namespace Actions {
    class CombatAction {
    public:
        CombatAction();
        virtual ~CombatAction() = 0;
        [[nodiscard]] virtual std::string get_name() const = 0;
        virtual void execute(Entities::Character* user, Entities::Character* target) = 0;
    };
}
