class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> _ns;
        for(auto n : nums){
            if(!_ns.insert(n).second) return true;
        }
        return false;
    }
};