class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> _cc;
        for(auto cs : s)
            if(!_cc.insert({cs, 1}).second) _cc[cs]++;
        for (auto ct : t){
            if(!_cc.contains(ct)) return false;
        else
            _cc[ct]--;
        }
        for (auto& p : _cc)
            if(p.second != 0) return false;
        return true;
    }
};
