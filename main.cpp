#include "Components/MultiOptionInput.h"
#include <iostream>
#include <UIAnimation.h>
#include <vector>
#include <Combat/Combat.h>

int main() {
    Entities::Player player(100, 10);
    Entities::Enemy enemy(65, 10);

    Systems::Combat new_combat(player, enemy);
    new_combat.handle_combat();
    return 0;
}
