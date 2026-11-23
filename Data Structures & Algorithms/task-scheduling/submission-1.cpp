#include <algorithm>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::array<int, 26> freqs{};
        for (auto t : tasks)
            ++freqs[static_cast<unsigned char>(t) - 'A']; // potential UB
        
        std::sort(freqs.begin(), freqs.end(), std::greater<>());
        auto maxFreq = freqs[0];
        auto cntMax = 1;
        for (int i = 1; i < 26; ++i){
            if (freqs[i] == maxFreq)++cntMax;
            else break;
        }

        int cycle{std::max<int>(tasks.size(), (maxFreq - 1) * (n + 1) + cntMax)};
        
        return cycle;
    }
};
