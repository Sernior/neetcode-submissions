class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())return false;

        std::array<int, 256> s1Frequencies{};
        int totalNonZeroFrequencies{};


        auto updateFrequencies = [&](unsigned char c,int delta){
            if(s1Frequencies[static_cast<unsigned int>(c)] == 0){
                if(s1Frequencies[static_cast<unsigned int>(c)] + delta != 0){
                    ++totalNonZeroFrequencies;
                }
            }
            if(s1Frequencies[static_cast<unsigned int>(c)] != 0){
                if(s1Frequencies[static_cast<unsigned int>(c)] + delta == 0){
                    --totalNonZeroFrequencies;
                }
            }
            s1Frequencies[static_cast<unsigned int>(c)] += delta;
        };


        for (unsigned char c : s1){
            updateFrequencies(c, 1);
        }

        int i = 0;
        int j = s1.size() - 1;

        for (int k = i; k <= j; ++k){
            updateFrequencies(s2[k], -1);
        }


        while(j < s2.size() - 1){
            if (totalNonZeroFrequencies == 0)return true;
            else{
                updateFrequencies(s2[i], 1);
                updateFrequencies(s2[j+1], -1);
                ++i;
                ++j;
            }
        }

        if (totalNonZeroFrequencies == 0)return true;
        return false;
    }
};
