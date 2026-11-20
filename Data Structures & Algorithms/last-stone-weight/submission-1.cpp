class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::ranges::make_heap(stones.begin(), stones.end());
        while (stones.size() > 1) {
            std::ranges::pop_heap(stones);
            auto biggestStone = stones.back();
            stones.pop_back();
            std::ranges::pop_heap(stones);
            auto secondBiggestStone = stones.back();
            stones.pop_back();
            auto newStone = biggestStone - secondBiggestStone;
            if (newStone) {
                stones.push_back(newStone);
                std::ranges::push_heap(stones);
            }
        }
        return stones.size() ? stones[0] : 0;
    }
};
