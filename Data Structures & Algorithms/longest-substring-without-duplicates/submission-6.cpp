class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lSubStr{};
        std::array<int, 256> m;
        m.fill(-1);
        int i = 0;
        for (int j = i; j < s.size(); ++j){
            i = max(i, m[static_cast<unsigned char>(s[j])] + 1);
            m[static_cast<unsigned char>(s[j])] = j;
            lSubStr = max(lSubStr, j - i + 1);
        }
        return lSubStr;
    }
};
