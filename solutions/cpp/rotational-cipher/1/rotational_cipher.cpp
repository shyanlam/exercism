#include "rotational_cipher.h"
#include <cctype>
namespace rotational_cipher {

// TODO: add your solution here
    std::string rotate(const std::string& text, int rot) {
        const static std::string LOWER_CASE = "abcdefghijklmnopqrstuvwxyz";
        const static std::string UPPER_CASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        static auto convert = [&rot](const std::string& alphas, const char c) -> char {
            return alphas[(alphas.find(c) + rot) % 26];
        };

        std::string result(text);
        for (auto& c : result) {
            if (std::islower(c)) {
                c = convert(LOWER_CASE, c);
            } else if (std::isupper(c)) {
                c = convert(UPPER_CASE, c);
            } 
        }
        return result;
    }

}  // namespace rotational_cipher
