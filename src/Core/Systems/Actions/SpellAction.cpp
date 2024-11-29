#include "SpellAction.h"
#include "Components/MultiOptionInput.h"

namespace Actions {
    SpellAction::SpellAction() = default;

    SpellAction::~SpellAction() = default;

    std::string SpellAction::get_name() const {
        return "Use a spell.";
    }

    void SpellAction::execute(Entities::Character *user, Entities::Character *target) {
        const auto& spells = user->get_available_spells();

        UI::MultiOptionInput options("Select a spell to proceed", spells);
    }
}
