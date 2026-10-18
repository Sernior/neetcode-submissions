class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0)return 0;
        if (s.size()==1)return 1;
        int lSubStr{1};
        std::array<int, 256> m;
        m.fill(-1);
        int i = 0;
        m[static_cast<unsigned char>(s[i])] = i;
        for (int j = i + 1; j < s.size(); ++j){
            i = max(i, m[static_cast<unsigned char>(s[j])] + 1);
            m[static_cast<unsigned char>(s[j])] = j;
            lSubStr = max(lSubStr, j - i + 1);
        }
        return lSubStr;
    }
};
