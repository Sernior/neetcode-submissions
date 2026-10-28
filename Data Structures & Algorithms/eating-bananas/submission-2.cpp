#include<ranges>
class Solution {
public:
    int minEatingSpeed(vector<int> const& piles, int const h) {
        // i k sensati sono per k che va dalla somma di tutte le banane / h che e` il caso in cui sono perfettamente distribuite
        // e la pila con piu banane perche oltre quel punto non avrebbe senso aumentare k.
        int const minK = static_cast<int>(std::ceil(static_cast<double>(ranges::fold_left(piles, 0LL, plus{})) / h));
        int const maxK = ranges::max(piles);
        auto possibleKs = views::iota(minK, maxK + 1);
        auto minimumK = ranges::partition_point(possibleKs, [&piles, h](int k){
            int hours{};
            for(int p : piles)
                hours += static_cast<int>(std::ceil(static_cast<double>(p) / k));
            return hours > h;
        });
        return *minimumK;
    }
};
