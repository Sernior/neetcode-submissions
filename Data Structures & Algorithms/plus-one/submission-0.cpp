class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rest{};
        auto rb = digits.rbegin();
        int sum = *rb + 1;
        rest = sum / 10;
        *rb = sum % 10;
        ++rb;
        while (rb != digits.rend() && rest > 0) {
            int sum = *rb + rest;
            rest = sum / 10;
            *rb = sum % 10;
            ++rb;
        }
        if (rest) {
            digits.insert(digits.begin(), rest);
        }
        return digits;
    }
};
