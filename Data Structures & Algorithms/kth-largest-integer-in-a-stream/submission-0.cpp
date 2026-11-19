#include <utility>
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_{k} {
        for (auto num : nums){
            if (!numToCardinality.contains(num))numToCardinality.insert({num, 1});
            else ++numToCardinality[num];
        }
    }
    
    int add(int val) {
        if (!numToCardinality.contains(val))numToCardinality.insert({val, 1});
        else ++numToCardinality[val];
        int k = k_;
        for (auto const& numCard : numToCardinality){
            if (numCard.second >= k)return numCard.first;
            k -= numCard.second;
        }
        // There will always be at least k integers in the stream when you search for the kth integer.
        std::unreachable();
    }

private:
    std::map<int, int , std::greater<>> numToCardinality;
    int k_;
};
