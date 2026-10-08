class Solution {
    std::unordered_set<int> _ns;
public:
    bool hasDuplicate(vector<int>& nums) {
        for(auto&& n : nums){
            if (_ns.contains(n))
                return true;
            _ns.insert(n);
        }
        return false;
    }
};