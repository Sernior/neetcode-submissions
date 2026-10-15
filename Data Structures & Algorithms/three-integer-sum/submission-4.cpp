class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        auto step_right = [&nums](int& index){
            int pIndex = index;
            ++index;
            while (index < nums.size() && nums[pIndex] == nums[index]){
                pIndex = index;
                ++index;
            }
        };
        auto step_left = [&nums](int& index){
            int pIndex = index;
            --index;
            while (index >= 0 && nums[pIndex] == nums[index]){
                pIndex = index;
                --index;
            }
        };
        int i = 0;
        while(i < nums.size()){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                if (nums[i] + nums[j] + nums[k] == 0){
                    output.push_back({nums[i], nums[j], nums[k]});
                    step_left(k);
                    step_right(j);
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                    step_left(k);
                else if (nums[i] + nums[j] + nums[k] < 0)
                    step_right(j);
            }
            step_right(i);
        }
        return output;
    }
};
