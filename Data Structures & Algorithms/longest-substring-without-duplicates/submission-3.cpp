class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::array<int, 128> charToIndex;
        charToIndex.fill(-1);
        int i = 0;
        int j = 1;
        charToIndex[static_cast<unsigned int>(s[i])] = i;
        int lsubs = !s.size() ? 0 : 1;
        while(j < s.size()){
            i = max(i, charToIndex[static_cast<unsigned int>(s[j])] + 1);
            charToIndex[static_cast<unsigned int>(s[j])] = j;
            lsubs = max(lsubs, j - i + 1);
            ++j;
        }
        return lsubs;
    }
};
