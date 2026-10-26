class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        int totalNeed = t.size();
        std::array<int, 256> need;
        need.fill(0);
        for (char c : t)++need[static_cast<unsigned char>(c)];

        auto enterWindow = [&](char c){
            --need[static_cast<unsigned char>(c)];
            if (need[static_cast<unsigned char>(c)] >= 0)--totalNeed;
        };

        auto exitWindow = [&](char c){
            ++need[static_cast<unsigned char>(c)];
            if (need[static_cast<unsigned char>(c)] > 0)++totalNeed;
        };

        int i = 0;
        int j = 0;

        int minDistance = 100001;

        int minI = 0;
        int minJ = 0;

        while(j < s.size()){
            enterWindow(s[j]);
            ++j;
            while(!totalNeed){
                if (j - i < minDistance){
                    minI = i;
                    minJ = j;
                    minDistance = j - i;
                }
                exitWindow(s[i]);
                ++i;
            }
        }

        if (minDistance == 100001) return "";

        return s.substr(minI, minJ - minI);
    }
};
