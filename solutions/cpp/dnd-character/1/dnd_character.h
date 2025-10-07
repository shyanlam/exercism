#pragma once

namespace dnd_character {

// TODO: add your solution here
    int modifier(int constitution);
    int ability();
    struct Character {
        Character();
        int strength{};
        int dexterity{};
        int constitution{};
        int intelligence{};
        int wisdom{};
        int charisma{};
        int hitpoints{};
    };
}  // namespace dnd_character
