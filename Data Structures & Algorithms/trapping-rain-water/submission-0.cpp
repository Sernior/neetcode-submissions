class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxL = 0;
        int maxR = 0;
        int water = 0;
        while (i <= j){
            if (maxL < maxR){
                maxL = max(height[i], maxL);
                water += max(maxL - height[i], 0);
                ++i;
            }
            else{
                maxR = max(height[j], maxR);
                water += max(maxR - height[j], 0);
                --j;
            }
        }
        return water;
    }
};
