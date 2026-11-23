class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::ranges::nth_element(nums, nums.end() - k);
        return nums[nums.size() - k];
    }
};
