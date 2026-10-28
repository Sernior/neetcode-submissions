class Solution {
public:
    int findMin(vector<int> const& nums) {
        return *ranges::partition_point(nums, [&nums](int const n){
            return n > nums.back();
        });
    }
};
