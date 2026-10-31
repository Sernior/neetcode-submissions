class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, size_t k) {
        std::deque<size_t> deq;

        auto enterWindow = [&](size_t index){
            while (!deq.empty() && nums[deq.front()] < nums[index])deq.pop_front();
            deq.push_front(index);
        };

        auto exitWindow = [&](size_t index){
            if (!deq.empty() && deq.back() == index)deq.pop_back();
        };


        for (size_t i = 0; i < k; ++i){
            enterWindow(i);
        }

        std::vector<int> ret;
        ret.reserve(nums.size() - k + 1);

        ret.push_back(nums[deq.back()]);

        size_t i = 0;

        for (size_t j = k; j < nums.size(); ++j){
            exitWindow(i);
            enterWindow(j);
            ++i;
            ret.push_back(nums[deq.back()]);
        }

        return ret;
    }
};
