#include "zebra_puzzle.h"
#include <array>
#include <cassert>
#include <optional>
#include <string>
#include <set>
#include <vector>
#include <utility>

#define LOG_DETAILS

namespace zebra_puzzle {

    enum PROPERTY { Color, Nationality, Pet, Beverage, Hobby, property_count };

    constexpr int unknown = 0;
    enum COLOR { red = 1, green, ivory, yellow, blue };
    enum NATIONALITY { Englishman = 1, Spaniard, Ukrainian, Norwegian, Japanese };
    enum PET { dog = 1, snail, fox, horse, zebra };
    enum BEVERAGE { coffee = 1, tea, milk, orange_juice, water };
    enum HOBBY { dancing = 1, painter, reading, football, chess };

    constexpr int property_value_count = 5;
    constexpr int house_count = 5;
    constexpr unsigned int FIXED = 0xF0;
    constexpr unsigned int FIXED_MASK = ~FIXED;

    using house_properties_t = std::array<int, property_count>;
    using houses_t = std::array<house_properties_t, house_count>;

    std::string Nationality_str(NATIONALITY nationality) {
        switch (nationality) {
        case Englishman: return "Englishman";
        case Spaniard: return "Spaniard";
        case Ukrainian: return "Ukrainian";
        case Norwegian: return "Norwegian";
        case Japanese: return "Japanese";
        default: return "unknown";
        }
    }

    int get_property(const house_properties_t& house, PROPERTY property) {
        return house[property] & FIXED_MASK;
    }

    const std::optional<int> find_house(const houses_t& houses, PROPERTY property, int propertyValue) {
        for (int houseNo = 0; houseNo < house_count; ++houseNo) {
            if (get_property(houses[houseNo], property) == propertyValue)
                return houseNo;
        }
        assert(false);
        return std::nullopt;
    }

    bool check_property(const houses_t& houses, PROPERTY pType1, int pValue1, PROPERTY pType2, int pValue2) {
        for (const auto& house : houses) {
            if ((get_property(house, pType1) == pValue1) &&
                (get_property(house, pType2) == pValue2))
                return true;
        }
        return false;
    }

    bool check_neighbours(const houses_t& houses,
                          PROPERTY pType1, int value1,
                          PROPERTY pType2, int value2) {
        for (int houseNo1 = 0, houseNo2 = 1; houseNo2 < house_count; ++houseNo1, ++houseNo2) {
            auto& house1 = houses[houseNo1];
            auto& house2 = houses[houseNo2];
            if (((get_property(house1, pType1) == value1) && (get_property(house2, pType2) == value2)) ||
                ((get_property(house2, pType1) == value1) && (get_property(house1, pType2) == value2)))
                return true;
        }
        return false;
    }

    bool check_left_right(const houses_t& houses,
                          PROPERTY leftType, int leftValue,
                          PROPERTY rightType, int rightValue) {
        for (int left = 0, right = 1; right < house_count; ++left, ++right) {
            auto& leftHouse = houses[left];
            auto& rightHouse = houses[right];
            if ((get_property(leftHouse, leftType) == leftValue) && (get_property(rightHouse, rightType) == rightValue))
                return true;
        }
        return false;
    }

    template <typename E>
    void set_property(houses_t& houses, PROPERTY property, std::vector<E>& values) {
        size_t n_val{ 0 };
        for (int houseNo = 0; houseNo < house_count; ++houseNo) {
            auto& house = houses[houseNo];
            if (!(house[property] & FIXED)) {
                house[property] = values[n_val];
                ++n_val;
            }
        }
    }

    Solution solve() {
        houses_t houses{};

        //10. The Norwegian lives in the first house.
        houses[0][Nationality] = Norwegian | FIXED;

        // 15. The Norwegian lives next to the blue house (2nd house).
        houses[1][Color] = blue | FIXED;

        //9. The person in the middle house drinks milk.
        houses[2][Beverage] = milk | FIXED;

        std::vector<COLOR> color{ red, green, ivory, yellow, /*blue*/ };
        std::vector<NATIONALITY> nationality{ Englishman, Spaniard, Ukrainian, /*Norwegian,*/ Japanese };
        std::vector<PET> pet{ dog, snail, fox, horse, zebra };
        std::vector<BEVERAGE> beverage{ coffee, tea, /*milk,*/ orange_juice, water };
        std::vector<HOBBY> hobby{ dancing, painter, reading, football, chess };
        std::optional<houses_t> solution{};

        do { // color
            set_property(houses, Color, color);

            // 15. The Norwegian lives next to the blue house (2nd house).
            assert(get_property(houses[1], Color) == blue);

            //6. The green house is immediately to the right of the ivory house.
            if (!check_left_right(houses, Color, ivory, Color, green))
                continue;

            do { // Nationality
                set_property(houses, Nationality, nationality);

                //10. The Norwegian lives in the first house.
                assert(get_property(houses[0], Nationality) == Norwegian);

                //2. The Englishman lives in the red house.
                if (!check_property(houses, Color, red, Nationality, Englishman))
                    continue;

                do { // Beverage
                    set_property(houses, Beverage, beverage);

                    //9. The person in the middle house drinks milk.
                    assert(get_property(houses[2], Beverage) == milk);

                    //4. The person in the green house drinks coffee.
                    if (!check_property(houses, Color, green, Beverage, coffee))
                        continue;

                    //5. The Ukrainian drinks tea.
                    if (!check_property(houses, Nationality, Ukrainian, Beverage, tea))
                        continue;

                    do { // Pet
                        set_property(houses, Pet, pet);

                        //3. The Spaniard owns the dog.
                        if (!check_property(houses, Nationality, Spaniard, Pet, dog))
                            continue;

                        do { // Hobby
                            set_property(houses, Hobby, hobby);

                            //8. The person in the yellow house is a painter.
                            if (!check_property(houses, Color, yellow, Hobby, painter))
                                continue;

                            //14. The Japanese person plays chess.
                            if (!check_property(houses, Nationality, Japanese, Hobby, chess))
                                continue;

                            //13. The person who plays football drinks orange juice.
                            if (!check_property(houses, Beverage, orange_juice, Hobby, football))
                                continue;

                            //7. The snail owner likes to go dancing.
                            if (!check_property(houses, Pet, snail, Hobby, dancing))
                                continue;

                            //11. The person who enjoys reading lives in the house next to the person with the fox.
                            if (!check_neighbours(houses, Hobby, reading, Pet, fox))
                                continue;

                            //12. The painter's house is next to the house with the horse.
                            if (!check_neighbours(houses, Hobby, painter, Pet, horse))
                                continue;

                            // All test passed.  Solution found
                            auto drinkWater = find_house(houses, PROPERTY(Beverage), water);
                            auto ownsZebra = find_house(houses, PROPERTY(Pet), zebra);
                            assert(drinkWater.has_value());
                            assert(ownsZebra.has_value());
                            auto who_water = Nationality_str(static_cast<NATIONALITY>(get_property(houses[*drinkWater], Nationality)));
                            auto who_zebra = Nationality_str(static_cast<NATIONALITY>(get_property(houses[*ownsZebra], Nationality)));
                            return Solution{ who_water, who_zebra };

                        } while (std::next_permutation(hobby.begin(), hobby.end()));

                    } while (std::next_permutation(pet.begin(), pet.end()));

                } while (std::next_permutation(beverage.begin(), beverage.end()));

            } while (std::next_permutation(nationality.begin(), nationality.end()));

        } while (std::next_permutation(color.begin(), color.end()));

        return Solution{};
    }
}  // namespace zebra_puzzle