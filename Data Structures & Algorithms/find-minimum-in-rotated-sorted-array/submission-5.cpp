class Solution {
public:
    int findMin(vector<int> const& nums) {
        return *ranges::partition_point(nums, [last = nums.back()](int const n) {
            return n > last;
        });
    }
};
