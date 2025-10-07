#pragma once

namespace dnd_character {

// TODO: add your solution here
    int modifier(int constitution);
    int ability();
    struct Character {
        const int strength{ ability() };
        const int dexterity{ ability() };
        const int constitution{ ability() };
        const int intelligence{ ability() };
        const int wisdom{ ability() };
        const int charisma{ ability() };
        const int hitpoints{ 10 + modifier(constitution) };
    };
}  // namespace dnd_character
