class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> _sorted2Original;
        for (auto s : strs){
            auto original = s;
            std::sort(s.begin(), s.end());
            //std::cout << s << '\n';
            if (_sorted2Original.contains(s)) _sorted2Original[s].push_back(original);
            else _sorted2Original[s] = vector<string>{original};
        }
        vector<vector<string>> ret;
        for (auto& kv : _sorted2Original){
            ret.push_back(vector<string>{kv.second});
        }
        
        return ret;
    }
};
