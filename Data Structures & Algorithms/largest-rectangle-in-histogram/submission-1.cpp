class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // the stack always contains the indexes of those bars those height is lower than the i-th bar
        std::vector<int> barStack;
        barStack.reserve(heights.size());
        int max_area{};
        for (int i = 0; i < heights.size(); ++i){
            while(!barStack.empty() && heights[i] < heights[barStack.back()]){
                int h = heights[barStack.back()];
                barStack.pop_back();
                int l = barStack.empty() ? i : i - barStack.back() - 1;
                int area = l * h;
                max_area = max(max_area, area);
            }
            barStack.push_back(i);
        }
        int i = heights.size();
        while(!barStack.empty()){
            int h = heights[barStack.back()];
            barStack.pop_back();
            int l = barStack.empty() ? i : i - barStack.back() - 1;
            int area = l * h;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
