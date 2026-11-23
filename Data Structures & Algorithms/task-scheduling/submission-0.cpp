class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::array<int, 256> freqs{};
        for (auto t : tasks)
            ++freqs[static_cast<unsigned char>(t)];
        
        std::sort(freqs.begin(), freqs.end(), std::greater<>());

        int cycle{};
        auto allTasksCompleted = [&freqs](){
            for (auto f : freqs)
                if (f > 0) return false;
            return true;
        };
        for (;;) {
            for (int i = 0; i < n + 1; ++i){
                if (allTasksCompleted())break;
                ++cycle;
                --freqs[i];
            }
            std::sort(freqs.begin(), freqs.end(), std::greater<>());
            if (allTasksCompleted())break;
        }
        return cycle;
    }
};
