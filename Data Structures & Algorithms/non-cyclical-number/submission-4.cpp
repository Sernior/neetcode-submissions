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

        auto slow = n;
        auto fast = nextIteration(n);
        for(;;){
            if (fast == 1)return true;
            if (slow == fast)return false;
            slow = nextIteration(slow);
            fast = nextIteration(nextIteration(fast));
        }
    }
};
