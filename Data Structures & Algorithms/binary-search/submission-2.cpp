class Solution {
public:
    int search(vector<int>& nums, int target) {
        std::ptrdiff_t n = nums.size();
        std::ptrdiff_t left{}, right{n};
        while (left < right){
            std::ptrdiff_t current = std::midpoint(left, right);
            if (nums[current] == target)return current;
            else if (nums[current] > target)right = current;
            else left = current + 1;
        }

        return -1;
    }
};
