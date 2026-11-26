class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret{};
        for (auto n : nums)
            ret ^= n;
        return ret;
    }
};
// 2x + 2y + z = 34