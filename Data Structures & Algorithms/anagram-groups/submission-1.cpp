class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> _sorted2Original;
        for (const auto& s : strs){
            auto key = s;
            std::sort(key.begin(), key.end());
            //std::cout << s << '\n';
            if (_sorted2Original.contains(key)) _sorted2Original[key].push_back(s);
            else _sorted2Original[key] = vector<string>{s};
        }
        vector<vector<string>> ret;
        for (auto& kv : _sorted2Original){
            ret.push_back(vector<string>{std::move(kv.second)});
        }
        
        return ret;
    }
};
