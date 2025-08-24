#include "rotational_cipher.h"
#include <cctype>
namespace rotational_cipher {

// TODO: add your solution here
    std::string rotate(const std::string& text, int rot) {
        std::string result(text);
        for (auto& c : result) {
            if (std::isalpha(c)) {
                const auto base = std::islower(c) ? 'a' : 'A';
                c = base + ((c - base + rot) % 26);
            }
        }
        return result;
    }

}  // namespace rotational_cipher
