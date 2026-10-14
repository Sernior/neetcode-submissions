#include<ranges>
class Solution {
public:
    bool isPalindrome(string s) {
        auto alnum = [](unsigned char c) { return std::isalnum(c) != 0; };
        auto lower = [](unsigned char c) { return static_cast<char>(std::tolower(c)); };
        auto pulita = s | views::filter(alnum) | views::transform(lower);
        return ranges::equal(pulita, pulita | views::reverse);
    }
};
