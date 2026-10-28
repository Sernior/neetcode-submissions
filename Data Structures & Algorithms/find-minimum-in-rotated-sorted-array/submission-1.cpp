class Solution {
public:
    int findMin(vector<int> &nums) {
        int const back = nums.back();
        auto min = ranges::partition_point(nums, [back](int const n){
            return n > back;
        });
        return *min;
    }
};
