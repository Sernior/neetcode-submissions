class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int lastElem = 1;
        vector<int> output(nums);
        for(int i = 1; i < nums.size(); ++i){
            if (i == 1){
                lastElem = nums[i];
                nums[i] = nums[0];
                nums[0] = 1;
                continue;
            }
            auto oldLast = lastElem;
            lastElem = nums[i];
            nums[i] = nums[i-1]*oldLast;
        }

        lastElem = 1;
        for(int i = output.size()-1; i >= 0; --i){
            if (i == output.size()-1){
                lastElem = output[i];
                output[i] = nums[i];
                continue;
            }
            int tmp = output[i];
            output[i] = lastElem * nums[i];
            lastElem *= tmp;
        }
        
        

        return output;
    }
};
