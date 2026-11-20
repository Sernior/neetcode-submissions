#include <utility>
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_{k} {
        for (int n : nums)
            heap_.push(n);
        while (heap_.size() > k_) heap_.pop();
    }
    
    int add(int val) {
        heap_.push(val);
        while (heap_.size() > k_) heap_.pop();
        return heap_.top();
    }

private:
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<>> heap_;
};
