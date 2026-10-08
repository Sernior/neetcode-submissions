class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> _ns;
        for(auto n : nums){
            if (_ns.contains(n))
                return true;
            _ns.insert(n);
        }
        return false;
    }
};