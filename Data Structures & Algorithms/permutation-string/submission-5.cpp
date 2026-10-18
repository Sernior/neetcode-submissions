class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())return false;

        std::array<unsigned int, 256> freq1{};
        std::array<unsigned int, 256> freq2{};

        for(char c : s1)++freq1[static_cast<unsigned char>(c)];

        for(int j = 0; j < s1.size(); ++j)++freq2[static_cast<unsigned char>(s2[j])];

        int i = 0;

        for(int j = s1.size() - 1; j < s2.size(); ++j){
            if (freq1 == freq2) return true;
            --freq2[static_cast<unsigned char>(s2[i])];
            ++i;
            ++freq2[static_cast<unsigned char>(s2[j+1])];
        }

        return freq1 == freq2;
    }
};
