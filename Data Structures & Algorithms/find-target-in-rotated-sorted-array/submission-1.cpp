#include<utility>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto minPoint = ranges::partition_point(nums, [last = nums.back()](int const n) {
            return n > last;
        });

        int const back = nums.back();
        int const front = nums.front();
        
        if (target <= back)// right
        {
            auto lb = ranges::lower_bound(minPoint, nums.end(), target);
            if (lb == nums.end())return -1;
            return *lb == target ? std::distance(nums.begin(), lb) : -1;
        }
        else // left
        {
            auto lb = ranges::lower_bound(nums.begin(), minPoint, target);
            return *lb == target ? std::distance(nums.begin(), lb) : -1;
        }

        std::unreachable();
    }
};
