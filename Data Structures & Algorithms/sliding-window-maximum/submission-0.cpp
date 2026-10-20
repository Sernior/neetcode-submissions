class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> ret{};
        ret.reserve(nums.size() - k + 1);
        std::deque<int> deq{};
        auto popBackUntilGreater = [&](int index){
            while(!deq.empty() && nums[deq.back()] <= nums[index])deq.pop_back();
            deq.push_back(index);
        };
        int i{};

        for(int j = 0; j < nums.size(); ++j){
            i = j - k + 1;
            popBackUntilGreater(j);
            if (i > 0 && i - 1 == deq.front()){
                deq.pop_front();
            }
            if (i >= 0){
                ret.push_back(nums[deq.front()]);
            }
        }
        return ret;
    }
};
