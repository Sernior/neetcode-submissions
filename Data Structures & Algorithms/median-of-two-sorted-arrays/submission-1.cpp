#include <span>
class Solution {
public:
    double findMedianSortedArrays(vector<int> const& shortest, vector<int> const& longest) {
        if (shortest.size() > longest.size())return findMedianSortedArrays(longest, shortest);
        auto calcMedian = [](span<const int> const v){
            if (v.size() % 2 == 1)return static_cast<double>(v[v.size() / 2]);
            else return static_cast<double>((v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2.0);
        };
        std::span<const int> s = shortest;
        std::span<const int> l = longest;
        if (s.size() == 0)return calcMedian(l);
        while(s.size() > 2){
            double shortestMedian = calcMedian(s);
            double longestMedian = calcMedian(l);
            if (shortestMedian >= longestMedian){
                int k = (s.size() - 1) / 2;
                s = s.first(s.size() - k);
                l = l.last(l.size() - k);
            }
            else{
                int k = (s.size() - 1) / 2;
                s = s.last(s.size() - k);
                l = l.first(l.size() - k);
            }
        }
        size_t w = (l.size() % 2 == 1) ? 3 : 4;
        w = std::min(w, l.size());
        auto mid = l.subspan((l.size() - w) / 2, w);
        vector<int> group(s.begin(), s.end());
        group.insert(group.end(), mid.begin(), mid.end());
        std::ranges::sort(group);
        return calcMedian(group);
    }
};
