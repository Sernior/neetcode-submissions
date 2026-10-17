class Solution {
public:
    int characterReplacement(string s, int k) {
        std::array<int, 256> frequency{};
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
        int i = 0;
        int j = 1;
        ++frequency[static_cast<unsigned int>(s[i])];
        int max_freq = 1;
        int longest = 1;
        while(j < s.size()){
            max_freq = max(max_freq, ++frequency[static_cast<unsigned int>(s[j])]);
            if (j - i + 1 > max_freq + k){
                --frequency[static_cast<unsigned int>(s[i])];
                ++i;
            }
            longest = max(longest, j - i + 1);
            ++j;
        }
        return longest;
    }
};
