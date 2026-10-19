class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())return "";
        std::array<int, 256> need;
        int needCount{static_cast<int>(t.size())};
        std::optional<std::pair<int, int>> minWindowIndexes;
        need.fill(0);
        for (char c : t)++need[static_cast<uint8_t>(c)];

        int i{};
        for(int j = 0; j < s.size(); ++j){
            if(need[static_cast<uint8_t>(s[j])] > 0)--needCount;
            --need[static_cast<uint8_t>(s[j])];

            while(needCount == 0){
                if(!minWindowIndexes.has_value())minWindowIndexes = {i, j};
                else if(minWindowIndexes->second - minWindowIndexes->first > j-i)minWindowIndexes = {i, j};
                ++need[static_cast<uint8_t>(s[i])];
                if(need[static_cast<uint8_t>(s[i])] > 0)++needCount;
                ++i;
            }
        }
        return minWindowIndexes.has_value() ? s.substr(minWindowIndexes->first, minWindowIndexes->second - minWindowIndexes-> first + 1) : "";
    }
};
