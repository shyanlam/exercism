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

    using house_properties_t = std::array<int, property_count>;
    using houses_t = std::array<house_properties_t, house_count>;

#define CASE_ENUM(e) case e: return #e
    std::string Nationality_str(NATIONALITY nationality) {
        switch (nationality) {
            CASE_ENUM(unknown);
            CASE_ENUM(Englishman);
            CASE_ENUM(Spaniard);
            CASE_ENUM(Ukrainian);
            CASE_ENUM(Norwegian);
            CASE_ENUM(Japanese);
        }
        return "?";
    }

    bool check_property(const houses_t& houses, PROPERTY propType1, int propValue1, PROPERTY propType2, int propValue2) {
        for (auto& house : houses) {
            if (house[propType1] == propValue1 && house[propType2] == propValue2)
                return true;
        }
        return false;
    }
    bool check_neighbours(const houses_t& houses, PROPERTY propType1, int propValue1,
                          PROPERTY propType2, int propValue2) {
        for (int house1 = 0, house2 = house1 + 1; house2 < house_count; ++house1, ++house2) {
            if ((houses[house1][propType1] == propValue1) && (houses[house2][propType2] == propValue2) ||
                (houses[house1][propType2] == propValue2) && (houses[house2][propType1] == propValue1))
                return true;
        }
        return false;
    }

    bool check_left_right(const houses_t& houses, PROPERTY leftPropType, int leftPropValue,
                          PROPERTY rightPropType, int rightPropValue) {
        for (int left = 0, right = left + 1; right < house_count; ++left, ++right) {
            if (houses[left][leftPropType] == leftPropValue &&
                houses[right][rightPropType] == rightPropValue)
                return true;
        }
        return false;
    }

    bool check_facts(const houses_t& houses) {
        //10. The Norwegian lives in the first house.
        assert(houses[0][Nationality] == Norwegian);

        //15. The Norwegian lives next to the blue house.
        assert(houses[1][Color] == blue);

        //9. The person in the middle house drinks milk.
        assert(houses[2][Beverage] == milk);

        //6. The green house is immediately to the right of the ivory house.
        if (!check_left_right(houses, Color, ivory, Color, green)) {
            return false;
        }

        //2. The Englishman lives in the red house.
        if (!check_property(houses, Nationality, Englishman, Color, red)) {
            return false;
        }

        //8. The person in the yellow house is a painter.
        if (!check_property(houses, Color, yellow, Hobby, painter)) {
            return false;
        }

        //4. The person in the green house drinks coffee.
        if (!check_property(houses, Color, green, Beverage, coffee)) {
            return false;
        }

        //3. The Spaniard owns the dog.
        if (!check_property(houses, Nationality, Spaniard, Pet, dog)) {
            return false;
        }

        //5. The Ukrainian drinks tea.
        if (!check_property(houses, Nationality, Ukrainian, Beverage, tea)) {
            return false;
        }

        //14. The Japanese person plays chess.
        if (!check_property(houses, Nationality, Japanese, Hobby, chess)) {
            return false;
        }

        //7. The snail owner likes to go dancing.
        if (!check_property(houses, Pet, snail, Hobby, dancing)) {
            return false;
        }

        //13. The person who plays football drinks orange juice.
        if (!check_property(houses, Hobby, football, Beverage, orange_juice)) {
            return false;
        }

        //11. The person who enjoys reading lives in the house next to the person with the fox.
        if (!check_neighbours(houses, Hobby, reading, Pet, fox)) {
            return false;
        }

        //12. The painter's house is next to the house with the horse.
        if (!check_neighbours(houses, Hobby, painter, Pet, horse)) {
            return false;
        }

        return true;
    }

    bool is_valid(const houses_t& houses) {
        std::vector<std::set<int>> check_properties(property_count, {});

        for (int houseNo = 0; houseNo < house_count; ++houseNo) {
            const house_properties_t& house = houses[houseNo];
            for (int propType = 0; propType < property_count; ++propType) {
                if (house[propType] != unknown) {
                    check_properties[propType].insert(house[propType]);
                }
            }
        }

        for (const auto& property : check_properties) {
            if (property.size() != property_value_count)
                return false;
        }
        return true;
    }

    std::optional<house_properties_t> find_house(const houses_t& houses, PROPERTY property, int value) {
        for (const auto& house : houses) {
            if (house[property] == value)
                return house;
        }
        return std::nullopt;
    }

    void init(houses_t& houses) {
        //10. The Norwegian lives in the first house.
        houses[0][Nationality] = Norwegian;

        // 15. The Norwegian lives next to the blue house.
        houses[1][Color] = blue;

        //9. The person in the middle house drinks milk.
        houses[2][Beverage] = milk;
    }

    std::pair<bool, houses_t> try_solve(houses_t houses, 
                                        std::vector<COLOR>& color,
                                        std::vector<NATIONALITY>& nationality,
                                        std::vector<PET>& pet,
                                        std::vector<BEVERAGE>& beverage,
                                        std::vector<HOBBY>& hobby) {
        size_t nColor{ 0 }, nNationality{ 0 }, nPet{ 0 }, nBeverage{ 0 }, nHobby{ 0 };

        for (int houseNo{ 0 }; houseNo < house_count; ++houseNo) {
            auto& house = houses[houseNo];

            if (house[Color] == unknown) {
                house[Color] = color[nColor];
                ++nColor;
            }
            if (house[Nationality] == unknown) {
                house[Nationality] = nationality[nNationality];
                ++nNationality;
            }
            if (house[Pet] == unknown) {
                house[Pet] = pet[nPet];
                ++nPet;
            }
            if (house[Beverage] == unknown) {
                house[Beverage] = beverage[nBeverage];
                ++nBeverage;
            }
            if (house[Hobby] == unknown) {
                house[Hobby] = hobby[nHobby];
                ++nHobby;
            }
        }

        assert(nColor == color.size());
        assert(nNationality == nationality.size());
        assert(nPet == pet.size());
        assert(nBeverage == beverage.size());
        assert(nHobby == hobby.size());
        assert(is_valid(houses));
        return std::make_pair(check_facts(houses), houses);
    }
    
    Solution solve() {
        houses_t houses{};
        init(houses);
        std::vector<COLOR> color{ red, green, ivory, yellow, /*blue*/ };
        std::vector<NATIONALITY> nationality{ Englishman, Spaniard, Ukrainian, /*Norwegian,*/ Japanese };
        std::vector<PET> pet{ dog, snail, fox, horse, zebra };
        std::vector<BEVERAGE> beverage{ coffee, tea, /*milk,*/ orange_juice, water };
        std::vector<HOBBY> hobby{ dancing, painter, reading, football, chess };
        std::optional<houses_t> solution{};

        do {
            do {
                do {
                    do {
                        do {
                            auto result = try_solve(houses, color, nationality, pet, beverage, hobby);
                            if (result.first) {
                                solution = result.second;
                                break;
                            }
                        } while (std::next_permutation(color.begin(), color.end()));
                        if (solution)
                            break;
                    } while (std::next_permutation(nationality.begin(), nationality.end()));
                    if (solution)
                        break;
                } while (std::next_permutation(pet.begin(), pet.end()));
                if (solution)
                    break;
            } while (std::next_permutation(beverage.begin(), beverage.end()));
            if (solution)
                break;
        } while (std::next_permutation(hobby.begin(), hobby.end()));

        if (!solution) {
            return Solution{};
        }
        auto drinkWater = find_house(solution.value(), Beverage, water);
        auto ownZebra = find_house(solution.value(), Pet, zebra);
        
        return Solution{
            Nationality_str(NATIONALITY((*drinkWater)[Nationality])),
            Nationality_str(NATIONALITY((*ownZebra)[Nationality]))
        };
    }
}  // namespace zebra_puzzle