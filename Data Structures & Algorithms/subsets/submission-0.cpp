class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret{};
        vector<int> c{};
        sub_rec(nums, ret, c, 0);
        return ret;
    }
private:
    void sub_rec(vector<int> const& nums, vector<vector<int>>& ret, vector<int>& c, int start) {
        ret.push_back(c);
        if (start >= nums.size()) {
            return;
        }
        for(size_t i = start; i < nums.size(); ++i){
            c.push_back(nums[i]);
            sub_rec(nums, ret, c, i + 1);
            c.pop_back();
        }
    }
};
