#include "matching_brackets.h"
#include <string_view>
#include <map>
#include <set>
#include <stack>
namespace matching_brackets {

// TODO: add your solution here
    const std::map<char, char> MATCHING_BRACKET{
        {']', '['},
        {'}', '{'},
        {')', '('},
    };
    bool check(const std::string_view& data) {
        std::stack<char> brackets{};
        for (const auto ch : data) {
            switch (ch) {
            case '[': case '{': case '(':
                brackets.push(ch);
                break;

            case ']': case '}': case ')':
                if (!brackets.empty() && brackets.top() == MATCHING_BRACKET.at(ch))
                    brackets.pop();
                else
                    return false;
            }
        }
        return brackets.empty();
    }
}  // namespace matching_brackets
