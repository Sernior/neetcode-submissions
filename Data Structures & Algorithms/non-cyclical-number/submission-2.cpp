class Solution {
public:
    bool isHappy(unsigned int n) {
        auto nextIteration = [](unsigned int a){
            unsigned int ret{};
            while (a)
            {
                unsigned int rest = a % 10;
                a /= 10;
                ret += rest*rest;
            }
            return ret;
        };

        std::unordered_set<unsigned int> visited;
        for(;;){
            auto next = nextIteration(n);
            if (next == 1)return true;
            if (visited.contains(n))return false;
            visited.insert(n);
            n = next;
        }
    }
};
