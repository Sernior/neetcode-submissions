class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, vector<int>> v2i;
        for (int i = 0; i < nums.size(); ++i){
            if(v2i.contains(nums[i]))
                v2i[nums[i]].push_back(i);
            else
                v2i.insert({nums[i], vector<int>{i}});
        }
        for (int i = 0; i < nums.size(); ++i){
            int need = target - nums[i];
            if (v2i.contains(need)){
                for (auto j : v2i[need])
                    if (i != j) return vector<int>{i, j};
            }
        }
        return vector<int>{-1,-1};
    }
};
