class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::ranges::make_heap(nums);
        while (k > 1) {
            std::ranges::pop_heap(nums);
            nums.pop_back();
            --k;
        }
        std::ranges::pop_heap(nums);
        return nums.back();
    }
};
