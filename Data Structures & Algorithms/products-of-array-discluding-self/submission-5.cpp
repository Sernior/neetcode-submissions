#include <execution>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size()), suf(nums.size());
        exclusive_scan(execution::par, nums.begin(),  nums.end(),  out.begin(),  1, multiplies<>{});
        exclusive_scan(execution::par, nums.rbegin(), nums.rend(), suf.rbegin(), 1, multiplies<>{});
        transform(execution::par, out.begin(), out.end(), suf.begin(), out.begin(), multiplies<>{});
        return out;
    }
};
