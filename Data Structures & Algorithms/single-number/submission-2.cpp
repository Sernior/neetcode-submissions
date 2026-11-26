class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::ranges::fold_left(nums, 0, std::bit_xor{});
    }
};
// 2x + 2y + z = 34