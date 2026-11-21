class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](vector<int>& p1, vector<int>& p2){
            return abs(p1[0]*p1[0])+abs(p1[1]*p1[1]) < abs(p2[0]*p2[0])+abs(p2[1]*p2[1]);};
        std::ranges::make_heap(points, comp);
        while (points.size() > k){
            std::ranges::pop_heap(points, comp);
            points.pop_back();
        }
        return std::move(points);
    }
};
