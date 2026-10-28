#include<ranges>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // i k sensati sono per k che va dalla somma di tutte le banane / h che e` il caso in cui sono perfettamente distribuite
        // e la pila con piu banane perche oltre quel punto non avrebbe senso aumentare k.
        int minK = std::ceil(static_cast<double>(ranges::fold_left(piles, 0LL, plus{})) / h);
        int maxK = ranges::max(piles);
        auto possibleKs = views::iota(minK, maxK);
        auto minimumK = ranges::partition_point(possibleKs, [&piles, h](int k){
            int hours{};
            for(int i = 0; i < piles.size(); ++i)
                hours += std::ceil(static_cast<double>(piles[i]) / k);
            return hours > h;
        });
        return *minimumK;
    }
};
