class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto next = [&](size_t i){
            return nums[i];
        };
        size_t slow = 0;
        size_t fast = 0;
        for(;;){
            slow = next(slow);
            fast = next(next(fast));
            if (slow == fast)break;
        }
        size_t anotherSlow = 0;
        for(;;){
            slow = next(slow);
            anotherSlow = next(anotherSlow);
            if (slow == anotherSlow)break;
        }
        return slow;
    }
};
