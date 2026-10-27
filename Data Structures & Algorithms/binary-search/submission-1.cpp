class Solution {
public:
    int search(vector<int>& nums, int target) {
        std::ptrdiff_t n = nums.size();
        std::ptrdiff_t left{}, right{n};
        while (left < right){
            std::ptrdiff_t current = (left + right) / 2;
            if (nums[current] == target)return current;
            else if (nums[current] > target)right = current;
            else if (nums[current] < target)left = current + 1;
        }

        return -1;
    }
};
