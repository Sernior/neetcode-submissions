class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,size_t> num2Frequency;
        std::map<size_t,vector<int>, std::greater<>> frequency2Nums;
        for(auto num : nums)
            ++num2Frequency[num];
        for(auto& kv : num2Frequency)
            frequency2Nums[std::move(kv.second)].push_back(std::move(kv.first));
        std::vector<int> ret;
        while(k > 0)
            for(auto& freqNums : frequency2Nums){
                while(!freqNums.second.empty()){
                    ret.push_back(freqNums.second.back());
                    freqNums.second.pop_back();
                    --k;
                    if (k==0)return ret;
                }
            }

            
        return ret;
    }
};
