#include <utility>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::ptrdiff_t m{std::ssize(matrix)}, n{std::ssize(matrix[0])};
        std::ptrdiff_t up{}, down{m};
        auto isInRange = [](int a, int b, int k){
            if (k >= a && k <= b)return 0;
            else if (k < a)return -1;
            else if (k > b)return 1;
            std::unreachable();
        };
        while(up < down){
            std::ptrdiff_t current = std::midpoint(up, down);
            int l{matrix[current][0]}, r{matrix[current][n - 1]};
            int inRange = isInRange(l, r, target);
            if (inRange == 0){
                return search(matrix[current], target) != -1;
            }
            else if (inRange == -1){
                down = current;
            }
            else{
                up = current + 1;
            }
        }

        return false;
    }

private:
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
