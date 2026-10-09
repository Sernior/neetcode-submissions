class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> _sorted2Original;
        for (const auto& s : strs){
            auto key = s;
            std::sort(key.begin(), key.end());
            //std::cout << s << '\n';
            _sorted2Original[std::move(key)].push_back(s);
        }
        vector<vector<string>> ret;
        for (auto& kv : _sorted2Original){
            ret.push_back(vector<string>{std::move(kv.second)});
        }
        
        return ret;
    }
};
