class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numsSet(nums.begin(),nums.end());
        std::vector<int> startes;
        startes.reserve(nums.size());
        if (nums.size()==0)return 0;
        for(int num : numsSet){
            if(!numsSet.contains(num-1))
                startes.push_back(num);
        }
        int maxSeq = 1;
        for(int starter : startes){
            int currentSeq = 1;
            while(numsSet.contains(starter + currentSeq))
                ++currentSeq;
            maxSeq = std::max(currentSeq, maxSeq);
        }
        return maxSeq;
    }
};
